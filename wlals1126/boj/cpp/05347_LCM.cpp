#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T-- > 0) {
        long long a, b;
        cin >> a >> b;

        long long lcm = a * b / gcd(a, b);

        cout << lcm << "\n";
    }

    return 0;
}
