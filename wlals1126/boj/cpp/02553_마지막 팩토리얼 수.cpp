#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, tmp;
    cin >> N;
    int* dp = new int[N + 1];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;
    dp[4] = 4;

    for (int i = 5; i <= N; i++) {
        if (i % 5 == 0) {
            tmp = i / 5;
            dp[i] = (dp[tmp] * static_cast<int>(pow(2, tmp % 4))) % 10;
        } else {
            tmp = (i / 5) * 5;
            dp[i] = dp[tmp];
            
            for (int j = tmp + 1; j <= i; j++) {
                dp[i] = dp[i] * j % 10;
            }
        }
    }

    cout << dp[N] << endl;
    delete[] dp;

    return 0;
}
