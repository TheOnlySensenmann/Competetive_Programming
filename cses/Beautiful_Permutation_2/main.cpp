#include <chrono>
#include <format>
#include <iostream>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> permutation;
set<int> unusedNumbers;
stack<set<int>::iterator> st;

string soloution;

bool changed = false;

void perm(int depth);

string permWithStack() {
    while (true) {
        if (st.size() == n) {
            ostringstream os;
            for (int c: permutation) {
                os << c + 1 << " ";
            }
            return os.str();
        }
        while (permutation.size() >= 2 && abs(permutation.back() - permutation[permutation.size() - 2]) == 1) {
            unusedNumbers.insert(permutation.back());
            permutation.pop_back();
            ++st.top();
            while (st.top() == unusedNumbers.end()) {
                st.pop();
                permutation.pop_back();
                ++st.top();
            }
            permutation.push_back(*st.top());
            unusedNumbers.erase(*st.top());
        }

        st.push(unusedNumbers.begin());
        permutation.push_back(*st.top());
        unusedNumbers.erase(*st.top());
    }
}

int main() {
    cin >> n;

    // auto start = chrono::high_resolution_clock::now();


    for (int i = 0; i < n; i++) {
        unusedNumbers.insert(i);
    }

    //cout <<permWithStack() << endl;


    // auto end = chrono::high_resolution_clock::now();
    // auto duration = end - start;
    // auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
    perm(0);

    ostringstream os;
    for (int i: permutation) {
        os << i + 1 << " ";
    }
    cout << os.str() << endl;
    //cout << ms << endl;
    return 0;
}


void perm(int depth) {
    if (depth == n) {
        ostringstream os;
        for (int i: permutation) {
            os << i + 1 << " ";
        }
        changed = true;
        soloution = os.str();
        return;
    }
    for (auto it = unusedNumbers.begin(); it != unusedNumbers.end(); ++it) {
        int i = *it;
        if (!permutation.empty() && abs(i - permutation.back()) == 1) {
            continue;
        }
        it = unusedNumbers.erase(it);
        permutation.push_back(i);
        perm(depth + 1);
        if (changed) {
            return;
        }
        permutation.pop_back();
        it = unusedNumbers.insert(it, i);
    }
}
