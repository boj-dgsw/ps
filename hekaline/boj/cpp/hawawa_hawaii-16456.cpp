// Dynamic Programming
// Silver I

#include <bits/stdc++.h>

using namespace std;

constexpr int DIV = 1'000'000'009;

int main()
{
    int n;
    cin >> n;

    vector<int> memo { 0, 1, 1, 2 };
    memo.resize(n + 1);
    for (int i = 4; i <= n; i++)
    {
        memo[i] = (memo[i - 1] + memo[i - 3]) % DIV;
    }

    cout << memo[n];
}
