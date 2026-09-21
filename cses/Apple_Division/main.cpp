#include <climits>
#include <vector>
using namespace std;
#include <iostream>

void subset(long k);

long n;
vector<long> apples;
vector<long> currentSearch;
long currentMinimum;

long sumOfApples;


int main() {
    currentMinimum = LONG_MAX;

    cin >> n;
    apples.resize(n);
    for (long i = 0; i < n; i++) {
        cin >> apples.at(i);
        sumOfApples += apples.at(i);
    }

    subset(0);

    cout << currentMinimum << endl;
    return 0;
}


void subset(long k) {
    if (k == n) {
        long sum = 0;
        for (long i : currentSearch) {
            sum += apples[i];
        }
        long sum2 = sumOfApples - sum;
        if (abs(sum - sum2) < currentMinimum) {
            currentMinimum = abs(sum - sum2);
        }
        return;
    }
    subset(k+1);
    currentSearch.push_back(k);
    subset(k+1);
    currentSearch.pop_back();
}