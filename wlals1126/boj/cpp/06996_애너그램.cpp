#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string s1, s2;
        ss >> s1 >> s2;

        vector<int> alphaCnt(26, 0);

        for (char c : s1) {
            alphaCnt[c - 'a']++;
        }

        for (char c : s2) {
            alphaCnt[c - 'a']--;
        }

        bool valid = true;
        for (int count : alphaCnt) {
            if (count != 0) {
                valid = false;
                break;
            }
        }

        cout << s1 << " & " << s2 << " are " << (valid ? "anagrams.\n" : "NOT anagrams.\n");
    }

    return 0;
}
