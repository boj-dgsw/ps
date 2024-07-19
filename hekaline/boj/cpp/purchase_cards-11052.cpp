#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> memo;
int n;

int main()
{
    cin >> n;
    memo.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> memo[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {a
            // cout << j << ' ' << i - j << '\n';
            memo[i] = max(memo[i], memo[j] + memo[i - j]);
        }
    }

    cout << memo[n];
}
