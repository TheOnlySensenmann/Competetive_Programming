#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

string characters;

set<string> permutations;

void goLayer(vector<bool> usedIndexes, string currentCharacters, size_t usedCharacters);

int main() {
    cin >> characters;


    vector<bool> usedIndexes(characters.size(), false);

    string currentCharacters = characters;

    goLayer(usedIndexes, currentCharacters, 0);

    cout << permutations.size() << endl;
    for (const auto& permutation : permutations) {
        cout << permutation << endl;
    }

    return 0;
}


void goLayer(vector<bool> usedIndexes, string currentCharacters, size_t usedCharacters) {
    if (usedCharacters == characters.size()) {
        permutations.insert(currentCharacters);
        return;
    }
    for (size_t i = 0; i < characters.length(); i++) {
        if (!usedIndexes[i]) {
            usedIndexes[i] = true;
            currentCharacters[usedCharacters] = characters[i];
            goLayer(usedIndexes, currentCharacters, usedCharacters + 1);
            usedIndexes[i] = false;
        }
    }
}




