// knapsack problem
// dynamic programming
// bruteforce
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int n;
vector<int> lose, joy;

void input();
int is_index_valid(int i)
{ return 0 <= i && i < 100; }

int main()
{
    FAST_IO;
    input();

    vector memo(n, vector<int>(101));

    // 첫 번째 사람에 대한 인사
    for (int i = lose[0]; i <= 100; i++)
    {
        memo[0][i] = joy[0];
    }

    // 2~n번째 사람에 대한 인사
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            memo[i][j] = memo[i - 1][j];

            if (j >= lose[i])
            {
                memo[i][j] = max(memo[i][j], memo[i - 1][j - lose[i]] + joy[i]);
            }
        }
    }

    cout << memo[n - 1][99];
}

void input()
{
    cin >> n;

    lose.resize(n);
    joy.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lose[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> joy[i];
    }
}
