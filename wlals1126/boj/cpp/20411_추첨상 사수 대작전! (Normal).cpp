#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long m, Seed, X1, X2;
    cin >> m >> Seed >> X1 >> X2;

    for (long long i = 0; i < m; ++i) {
        long long c = (X1 - i * Seed) % m;
        if (c < 0) c += m;
        if ((i * X1 + c) % m == X2) {
            cout << i << " " << c << endl;
            return 0;
        }
    }
    return 0;
}
