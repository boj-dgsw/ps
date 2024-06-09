#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);

    vector<char> stack;
    string target = "UCPC";
    int cnt = 0;

    for (char c : line) {
        if (cnt < target.size() && c == target[cnt]) {
            cnt++;
        }
    }

    cout << (cnt == 4 ? "I love UCPC" : "I hate UCPC") << endl;
    return 0;
}
