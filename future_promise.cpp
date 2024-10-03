#include <queue>
#include <mutex>
#include <thread>
#include <vector>
#include <future>
#include <iostream>

// Потокобезопасная очередь
template<typename T>
class ThreadSafeQueue {
private:
    std::queue<T> queue;
    mutable std::mutex m;

public:
    ThreadSafeQueue() {}

    // Добавление элемента в очередь
    void push(T value) {
        std::lock_guard<std::mutex> lock(m);
        queue.push(std::move(value));
    }

    // Извлечение элемента из очереди
    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if (queue.empty()) {
            return false;
        }
        value = std::move(queue.front());
        queue.pop();
        return true;
    }
};

// Функция отправки данных клиенту (имитация)
void send_data_to_client(int data, int client_id) {
    // Имитация отправки данных
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::string log_info = "Data sent to client " + std::to_string(client_id) + ": " + std::to_string(data ) + '\n';
    std::cout << log_info << std::flush;
}

int main() {
    ThreadSafeQueue<int> data_queue;
    std::vector<std::future<void>> futures;

    // Заполнение очереди данными
    for (int i = 0; i < 10; ++i) {
        data_queue.push(i);
    }

    // Создание пула потоков для отправки данных
    for (int i = 0; i < 5; ++i) {
        futures.push_back(std::async(std::launch::async, [&data_queue, i](){
            int data;
            while (data_queue.try_pop(data)) {
                send_data_to_client(data, i);
            }
        }));
    }

    // Ожидание завершения всех потоков
    for (auto& f : futures) {
        f.get();
    }

    return 0;
}
