#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);

    long long ans = 0;
    long long curNum = 0;

    for (int i = 0; i < n; ++i) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            curNum = curNum * 10 + (c - '0');
        } else {
            ans += curNum;
            curNum = 0;
        }
    }

    ans += curNum;
    cout << ans << endl;

    return 0;
}
