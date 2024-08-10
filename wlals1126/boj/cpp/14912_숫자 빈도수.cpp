#include <iostream>
#include <string>

using namespace std;

int main() {
    int num, x;
    cin >> num >> x;

    int cnt = 0;

    for (int i = 1; i <= num; i++) {
        string str = to_string(i);

        for (char c : str) {
            if (x == c - '0') {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
