#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#include <array>
using namespace std;

vector<stack<int>> stacks;
vector<array<int,2>> bestMoves;

void move (int depth, int from, int to);

int main() {
    int n;
    cin>>n;

    stacks.emplace_back();
    stacks.emplace_back();
    stacks.emplace_back();

    for(int i=n;i>0;i--) {
        stacks[0].push(i);
    }

    move (n, 0,2);

    cout << bestMoves.size() << endl;

    for(auto & bestMove : bestMoves) {
        cout << std::to_string(bestMove[0]) + " " + to_string(bestMove[1]) << endl;
    }

}


void move(const int depth, const int from, const int to) {
    if (depth == 0) {
        return;
    }
    int free = -1;
    for (int i = 0; i<=2; i++) {
        if (i != from && i != to) {
            free = i;
        }
    }

    move(depth - 1, from, free);
    stacks[to].push(stacks[from].top());
    stacks[from].pop();
    bestMoves.push_back({from + 1, to + 1});
    move(depth - 1, free, to);
}