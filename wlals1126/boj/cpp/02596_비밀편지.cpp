#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> str = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
vector<char> str2 = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

char encrypt(const string &s) {
    for (int i = 0; i < 8; ++i) {
        int diff = 0;
        for (int j = 0; j < 6; ++j) {
            if (s[j] != str[i][j]) {
                diff++;
            }
        }
        if (diff <= 1) {
            return str2[i];
        }
    }
    return 'X';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < n; ++i) {
        string s2 = s.substr(i * 6, 6);
        char enc = encrypt(s2);
        if (enc == 'X') {
            ans = to_string(i + 1);
            break;
        }
        ans += enc;
    }

    cout << ans << endl;

    return 0;
}
