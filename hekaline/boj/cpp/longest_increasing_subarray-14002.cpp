#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n;
int maxLen = 1;
int maxIdx = 0;
vector<int> arr;
vector<int> memo;

void input();
void makeMemo();
void printLIS();

int main()
{
    FAST_IO;
    input();
    makeMemo();

    cout << maxLen << '\n';
    printLIS();
}

void printLIS()
{
    int maxLenTemp = maxLen;
    vector<int> ans;

    for (int i = maxIdx; i >= 0 && maxLenTemp != 0; i--)
    {
        if (memo[i] == maxLenTemp)
        {
            maxLenTemp -= 1;
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    for (const auto& e : ans)
    {
        cout << e << ' ';
    }
}

void makeMemo()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                memo[i] = max(memo[i], memo[j] + 1);
                if (maxLen < memo[i])
                {
                    maxLen = memo[i];
                    maxIdx = i;
                }
            }
        }
    }
}

void input()
{
    cin >> n;
    arr.resize(n);
    memo.resize(n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
