#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    string s;

    while (cin >> s && s != "end") {
        bool flag = false;

        bool has_vowel = any_of(s.begin(), s.end(), is_vowel);
        if (!has_vowel) {
            flag = true;
        }

        int vowel_count = 0, consonant_count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (is_vowel(s[i])) {
                vowel_count++;
                consonant_count = 0;
            } else {
                consonant_count++;
                vowel_count = 0;
            }
            if (vowel_count >= 3 || consonant_count >= 3) {
                flag = true;
                break;
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "<" << s << "> is not acceptable." << '\n';
        else
            cout << "<" << s << "> is acceptable." << '\n';
    }

    return 0;
}
