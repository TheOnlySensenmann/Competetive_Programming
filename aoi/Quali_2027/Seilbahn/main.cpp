#include <iostream>
#include <vector>


int main() {
    int n, p;
    std::cin >> n >> p;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    int cabinsPassed = 0;
    while (p > -1 && cabinsPassed < n) {
        p -= s[cabinsPassed];
        cabinsPassed ++;
    }

    if (cabinsPassed >= n && p > -1) {

        std::cout << 0 << std::endl;
    } else {
        std::cout<< cabinsPassed;
    }


}
