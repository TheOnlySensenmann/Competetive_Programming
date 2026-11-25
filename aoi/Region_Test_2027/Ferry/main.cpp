#include <iostream>
#include <vector>
using namespace std;


int main() {
    int numberOfFerries, persons;
    std::cin >> numberOfFerries >> persons;
    vector<int> ferries(numberOfFerries);
    for (int i = 0; i < numberOfFerries; ++i) {
        std::cin >> ferries[i];
    }

    for (int i = 0; i < numberOfFerries; ++i) {
        persons -= ferries[i];
        if (persons < 0) {
            cout << (i + 1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}