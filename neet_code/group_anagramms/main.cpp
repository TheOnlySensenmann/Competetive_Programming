#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <unordered_map>

using namespace std;

static const int CHARACTERS_SIZE = 26;


vector<string> parseInput(const string& input);
vector<vector<std::string> > groupAnagrams(vector<string> &strs);
void test();

int main() {
    string input_string;
    cin >> input_string;
    auto input = parseInput(input_string);

    for (auto str : groupAnagrams(input)) {
        for (auto i : str) {
            cout << i + ", ";
        }
        cout << endl;
    }
}


void test() {
    bitset<182> bitset;
    bitset.reset();
    bitset.flip();
    cout << bitset.to_string() << endl;
}

vector<string> parseInput(const string& input) {
    vector<string> result;
    stringstream ss(input);

    string word;
    while (getline(ss, word, '"')) {
        if (!word.empty() && word != "[" && word != "]" && word != "," && word != "strs=[") {
            result.push_back(word);
        }
    }

    return result;
}

vector<vector<std::string> > groupAnagrams(vector<string> &strs) {
    unordered_map<bitset<182>, vector<string> > map;
    vector<vector<string> > res;
    for (const auto & str : strs) {
        bitset<182> bitset;
        for (int i = 0; i < str.length(); i++) {
            int n = str[i] - 'a';
            bitset.flip(n*7);
            while (!bitset.test(n)) {
                n++;
                bitset.flip(n);
            }
        }
        map[bitset].push_back(str);
    }
    for (auto const& key : map) {
        res.push_back(key.second);
    }
    return res;
}
