#include <iostream>
#include <cmath>

using namespace std;

long long calc(long long N, long long R) {
    long long sum = 0;
    long long P = N - R;

    for (long long i = 1; i <= static_cast<long long>(sqrt(P)); i++) {
        if (P % i == 0) {
            if (i > R) {
                sum += i;
            }
            if (i * i != P && P / i > R) {
                sum += P / i;
            }
        }
    }
    return sum;
}

int main() {
    long long N, R;
    cin >> N >> R;

    cout << calc(N, R) << endl;

    return 0;
}
