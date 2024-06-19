#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    while (getline(cin, line)) {
        s += line;
    }

    stringstream ss(s);
    string token;
    int sum = 0;
    while (getline(ss, token, ',')) {
        sum += stoi(token);
    }

    cout << sum << '\n';

    return 0;
}
