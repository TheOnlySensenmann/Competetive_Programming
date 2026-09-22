#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

string characters;

set<string> permutations;

void goLayer(bool usedIndexes[], string currentCharacters, int usedCharacters);

int main() {
    cin >> characters;


    bool usedIndexes[characters.size()];

    string currentCharacters = characters;

    goLayer(usedIndexes, currentCharacters, 0);

    cout << permutations.size() << endl;
    for (const auto& permutation : permutations) {
        cout << permutation << endl;
    }
}


void goLayer(bool usedIndexes[], string currentCharacters, int usedCharacters) {
    if (usedCharacters == characters.size()) {
        permutations.insert(currentCharacters);
        return;
    }
    for (int i = 0; i < characters.length(); i++) {
        if (!usedIndexes[i]) {
            usedIndexes[i] = true;
            currentCharacters[usedCharacters + 1] = characters[i];
            goLayer(usedIndexes, currentCharacters, usedCharacters + 1);
            usedIndexes[i] = false;
        }
    }
}




