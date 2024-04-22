#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string find_palindrome(const vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words.size(); ++j) {
            if (i == j) continue;
            string str = words[i] + words[j];
            if (is_palindrome(str)) {
                return str;
            }
        }
    }
    return "0";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        vector<string> words(k);
        for (int i = 0; i < k; ++i) {
            cin >> words[i];
        }
        string result = find_palindrome(words);
        cout << result << endl;
    }
    return 0;
}
