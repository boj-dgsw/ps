// DP
// [1][1]에서 [n][m]까지 가는 중 k번째 칸을 지나는 경우의 수 구하기

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> memo(n + 1, vector<long long>(m + 1));

    // [1][1]에서 [n][m]까지 가는 경우의 수 구하기
    for (int i = 1; i <= n; i++)
        memo[i][1] = 1;

    for (int j = 1; j <= m; j++)
        memo[1][j] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
        } 
    }
    // 경우의 수 구하기 끝

    // 지나야 하는 칸 없음
    if (k == 0)
        cout << memo[n][m];
    else
    {
        // [1][1] ~ [kI][kJ]까지 가는 경우의 수
        int kI = (k - 1) / m + 1;
        int kJ = k - (kI - 1) * m;

        // [kI][kJ] ~ [n][m]까지 가는 경우의 수 구하기
        int eI = n - kI + 1;
        int eJ = m - kJ + 1;

        // 곱하기
        cout << memo[kI][kJ] * memo[eI][eJ];
    }
}
