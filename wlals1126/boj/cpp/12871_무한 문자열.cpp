#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    if ((s + t).compare(t + s) == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
