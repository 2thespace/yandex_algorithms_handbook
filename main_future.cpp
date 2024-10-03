#include <iostream>
#include <thread>
#include <future>

// Вторая функция, которая будет выполняться в новом потоке
void processTask(std::promise<int>& p) {
    // Выполнение некоторой длительной задачи
    int result = 42; // В качестве примера просто вернем число 42
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Устанавливаем результат в promise
    p.set_value(result);
}

// Первая функция, которая отправляет задачу в новом потоке и получает результат
int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    // Отправляем задачу в новом потоке
    std::cout << " Отправка задачи " << std::endl;
    std::thread thread(processTask, std::ref(promise));
    
    // Ждем, пока задача завершится и получаем результат
    int result = future.get();

    // Выводим результат
    std::cout << "Результат выполнения задачи: " << result << std::endl;

    // Ожидаем завершения потока
    thread.join();

    return 0;
}