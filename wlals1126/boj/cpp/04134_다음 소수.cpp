#include <iostream>
#include <cmath>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        long long n;
        std::cin >> n;
        long long i = 0;

        if (n == 0 || n == 1)
            std::cout << 2 << std::endl;
        else {
            while (i * i <= n) {
                for (i = 2; i * i <= n; ++i) {
                    if (n % i == 0) {
                        i = 0;
                        n += 1;
                        break;
                    }
                }
            }
            std::cout << n << std::endl;
        }
    }

    return 0;
}
