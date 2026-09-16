#include <format>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::vector<int> zeroIndex(0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            zeroIndex.push_back(i);
        }
    }

    if (zeroIndex.size() <= k) {
        cout << n << endl;
        return 0;
    }

    int currentEndOfFreezesIndex = -1;
    int currentBeginningOfFreezesIndex = 0;
    int currentEndOfStreak = 0;
    int currentBeginningOfStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < zeroIndex.size() && k > 0; ++i) {
        a[zeroIndex[i]] = 2;
        k--;
        currentEndOfFreezesIndex = i;
    }

    while (currentEndOfStreak != n - 1) {
        currentEndOfStreak = currentEndOfFreezesIndex + 1 < zeroIndex.size() ? zeroIndex[currentEndOfFreezesIndex + 1] - 1 : n - 1;
        currentBeginningOfStreak = currentBeginningOfFreezesIndex - 1 >= 0 ? zeroIndex[currentBeginningOfFreezesIndex - 1] + 1 : 0;

        int currentStreak = currentEndOfStreak - currentBeginningOfStreak + 1;
        if (currentStreak >= longestStreak) {
            longestStreak = currentStreak;
        }

        currentEndOfFreezesIndex++;
        currentBeginningOfFreezesIndex++;
    }






    std::cout << longestStreak << std::endl;

    return 0;
}