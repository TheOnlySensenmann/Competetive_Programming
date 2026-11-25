#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> forbidden(n);
    for (int i = 0; i < n; ++i) getline(cin, forbidden[i]);

    string transcript;
    getline(cin, transcript);

    for (string s: forbidden) {
        if (transcript.find(s) != string::npos) {
            cout << "JA" << endl;
            return 0;
        }
    }

    cout << "NEIN\n";
    return 0;
}
