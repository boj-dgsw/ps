#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Serial {
    int len;
    int sum;
    string str;

    Serial(int len, int sum, const string& str) : len(len), sum(sum), str(str) {}
};

bool compare(const Serial& a, const Serial& b) {
    if (a.len == b.len) {
        if (a.sum == b.sum) {
            return a.str < b.str;
        }
        return a.sum < b.sum;
    }
    return a.len < b.len;
}

int main() {
    int n;
    cin >> n;
    vector<Serial> guitars;

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;

        int sum = 0;
        for (char ch : str) {
            if (isdigit(ch)) {
                sum += ch - '0';
            }
        }
        guitars.emplace_back(str.length(), sum, str);
    }

    sort(guitars.begin(), guitars.end(), compare);

    for (const Serial& s : guitars) {
        cout << s.str << "\n";
    }

    return 0;
}
