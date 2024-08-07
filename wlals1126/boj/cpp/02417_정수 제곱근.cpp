#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n <= 1) {
        cout << n << endl;
    } else {
        long long q = static_cast<long long>(floor(sqrt(n)));
        if (q * q >= n) {
            cout << q << endl;
        } else {
            cout << q + 1 << endl;
        }
    }

    return 0;
}
