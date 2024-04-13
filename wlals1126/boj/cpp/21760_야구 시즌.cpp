#include <iostream>
using namespace std;

long long solve(long long n, long long m, long long k, long long d) {
    long long p = (k * n * m * (m - 1) + n * m * m * (n - 1)) / 2;
    long long a = d / p * p;
    return a ? a : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, k, d;
        cin >> n >> m >> k >> d;
        cout << solve(n, m, k, d) << '\n';
    }

    return 0;
}
