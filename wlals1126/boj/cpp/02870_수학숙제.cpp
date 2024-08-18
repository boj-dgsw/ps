#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string convertToIntegerFormat(string s) {
    int i = 0;
    while (i < s.length() - 1 && s[i] == '0') {
        i++;
    }
    return s.substr(i);
}

int main() {
    int n;
    cin >> n;
    vector<string> numbers;
    cin.ignore();

    while (n-- > 0) {
        string line;
        getline(cin, line);
        string curNum = "";

        for (char c : line) {
            if (c >= '0' && c <= '9') {
                curNum += c;
            } else {
                if (!curNum.empty()) {
                    numbers.push_back(convertToIntegerFormat(curNum));
                    curNum = "";
                }
            }
        }

        if (!curNum.empty()) {
            numbers.push_back(convertToIntegerFormat(curNum));
        }
    }

    sort(numbers.begin(), numbers.end(), [](const string &o1, const string &o2) {
        if (o1.length() != o2.length()) return o1.length() < o2.length();
        return o1 < o2;
    });

    for (const string &num : numbers) {
        cout << num << endl;
    }

    return 0;
}
