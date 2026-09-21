#include <climits>
#include <vector>
using namespace std;
#include <iostream>

void subset(int k);

int n;
vector<int> apples;
vector<int> currentSearch;
int currentMinimum;

int sumOfApples;


int main() {
    currentMinimum = INT_MAX;

    cin >> n;
    apples.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> apples.at(i);
        sumOfApples += apples.at(i);
    }

    subset(0);

    cout << currentMinimum << endl;
    return 0;
}


void subset(int k) {
    if (k == n) {
        int sum = 0;
        for (int i : currentSearch) {
            sum += apples[i];
        }
        int sum2 = sumOfApples - sum;
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