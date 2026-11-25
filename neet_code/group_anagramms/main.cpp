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
    map<string, vector<int> > map;
    vector<vector<string> > res;
    for (int i = 0; i < strs.size(); i++) {
        string word = strs[i];
        sort(word.begin(), word.end());
        map[word].push_back(i);
    }
    for (auto key : map) {
        vector<string> res_part;
        for (auto item : key.second) {
            res_part.push_back(strs.at(item));
        }
        res.push_back(res_part);
    }
    return res;
}
