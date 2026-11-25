#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


vector<string> parseInput(const string& input);
vector<vector<std::string> > groupAnagrams(vector<string> &strs);

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
    map<string, vector<string> > map;
    vector<vector<string> > res;
    for (const auto & str : strs) {
        string word = str;
        sort(word.begin(), word.end());
        map[word].push_back(str);
    }
    for (auto key : map) {
        res.push_back(key.second);
    }
    return res;
}
