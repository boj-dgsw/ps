#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    getline(cin, input);

    stringstream ss(input);
    int a, b;
    char colon;
    ss >> a >> colon >> b;

    int g = gcd(a, b);
    cout << a / g << ':' << b / g << '\n';

    return 0;
}
