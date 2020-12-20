#include "day13.h"

void Day13::run() {
    std::ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        std::cout << "couldn't open file" << std::endl;
        return;
    }

    int earliest;
    file >> earliest;

    std::vector<std::pair<int, int>> buses;
    int i = 0;
    long long N = 1;
    for (int b; file >> b;) {
        buses.emplace_back(b, (b - (i%b))%b);
        N *= b;
        while (file.peek() == ',' || file.peek() == 'x') {
            if (file.peek() == 'x')
                ++i;
            file.ignore();
        }
        ++i;
    }
    file.close();

    int min = INT32_MAX; 
    int bus_min = 0;
    for (auto bus_pair : buses) {
        int bus = bus_pair.first;
        int waiting = bus - (earliest % bus);
        if (waiting < min) {
            min = waiting;
            bus_min = bus;
        }

    }
    assert(bus_min != 0);
    // std::cout << "res part 1 : " << min * bus_min << std::endl;

    long long ans = 0;
    for (auto bus_p : buses) {
        long long b = bus_p.first;
        int i = bus_p.second;

        long long ni = N/b;
        int mi = boost::integer::mod_inverse(ni, b);
        ans += i * ni * mi;
    }
    std::cout << ans << std::endl;
    std::cout << ans%N << std::endl;

}