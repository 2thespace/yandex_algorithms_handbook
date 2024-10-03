#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

struct pcap_pkthdr {
   struct timeval ts;  /* time stamp */
   uint32_t caplen;  /* length of portion present */
   uint32_t len;  /* length this packet (off wire) */
 };

struct pcap_t {

};

using pcap_handler = void(*)(u_char *, const struct pcap_pkthdr *);

int	pcap_loop(pcap_t *, int, pcap_handler, u_char *) {
    std::cout << "Zxc" << std::endl;
    return 0;
}

void packet_handler(u_char *param, const pcap_pkthdr *header, const u_char *pkt_data) {
    std::cout << "Echo" << std::endl;
}

class NikitaTest {
    NikitaTest(u_char *param, const pcap_pkthdr *header, const u_char *pkt_data):
    _param(param),_header(header), _pkt_data(pkt_data) {

    };

public:
    void start(pcap_handler function_ptr) {
        pcap_loop(_adhandle, 0, function_ptr, nullptr);
    }


private:
    pcap_t *_adhandle;
    const u_char *_pkt_data;
    u_char *_param;
    const pcap_pkthdr *_header;

};

int main(int argc, char ** argv) {
    int gifts, cash;
    std::cin >> gifts >> cash;
    std::vector<int> all_gifts;
    int gift_count = 0;
    while(gifts--) {
        
        int cost;
        std::cin >> cost;
        all_gifts.push_back(cost);

    }
    std::sort(all_gifts.begin(), all_gifts.end());
    for(auto& gift:all_gifts) {
        
        if(cash >= gift) {
            cash -=gift;
            gift_count++;
        } 
        else break;
    }
    std::cout << gift_count << std::endl;
}