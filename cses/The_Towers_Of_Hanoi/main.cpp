#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> stacks;
int k = 32;
vector<string> bestMoves;
vector<string> currentMoves;

void move (int depth, int n);

int main() {
    int n;
    cin>>n;

    stacks.emplace_back();
    stacks.emplace_back();
    stacks.emplace_back();

    for(int i=n;i>0;i--) {
        stacks[0].push_back(i);
    }

    move (0, n);

    cout << k << endl;

    for(int i=0;i<bestMoves.size();i++) {
        cout << bestMoves[i] << endl;
    }

}


void move(int depth, int n) {
    if (depth >= k) {
        return;
    }
    if (stacks[2].size() == n) {
        k = depth;
        bestMoves = currentMoves;
        return;
    }
    for (int moveFrom=0;moveFrom<3;moveFrom++) {
        for (int moveTo=2;moveTo>=0;moveTo--) {
            if (moveFrom == moveTo) {
                continue;
            }
            if (stacks[moveFrom].empty()) {
                continue;
            }
            if (!stacks[moveTo].empty() && stacks[moveFrom].back() > stacks[moveTo].back()) {
                continue;
            }
            stacks[moveTo].push_back(stacks[moveFrom].back());
            stacks[moveFrom].pop_back();
            currentMoves.push_back(std::to_string(moveFrom + 1) + " " + to_string(moveTo + 1));
            move(depth+1,n);
            currentMoves.pop_back();
            stacks[moveFrom].push_back(stacks[moveTo].back());
            stacks[moveTo].pop_back();
        }
    }


}