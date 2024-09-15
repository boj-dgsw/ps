#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool valid_name(const string& s) {
    for (int i = 0; i < s.size() - 2; ++i) {
        if ((is_vowel(s[i]) && is_vowel(s[i + 1]) && is_vowel(s[i + 2])) ||
            (!is_vowel(s[i]) && !is_vowel(s[i + 1]) && !is_vowel(s[i + 2]))) {
            return false;
        }
    }
    return true;
}

vector<string> generate_names(int n) {
    vector<string> names;
    string current = "aaa";
    while (names.size() < n) {
        if (valid_name(current)) {
            names.push_back(current);
        }
        int pos = current.size() - 1;
        while (pos >= 0 && current[pos] == 'z') {
            current[pos] = 'a';
            --pos;
        }
        if (pos >= 0) {
            ++current[pos];
        } else {
            current += 'a';
        }
    }
    return names;
}

int main() {
    int n;
    cin >> n;
    vector<string> names = generate_names(n);
    for (const string& name : names) {
        cout << name << endl;
    }
    return 0;
}
