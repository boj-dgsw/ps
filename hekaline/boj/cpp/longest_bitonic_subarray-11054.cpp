// DP
// 가장 긴 증가하는 부분수열 길이 + 가장 긴 감소하는 부분수열 길이
// Gold IV

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void input();
int getBitonicArrayLength();

int main()
{
    input();
    cout << getBitonicArrayLength();
}

int getBitonicArrayLength()
{
    vector<int> memo(n);
    vector<int> rMemo(n);

    for (int i = 0; i < n; i++)
    {
        memo[i] = 1;
        for (int j = 0; j < i; j++)
        {
            // 이전 수보다 현재 수(i번째)가 더 크고
            // 기록이 안 되어 있다면
            if (arr[j] < arr[i] && memo[j] >= memo[i])
            {
                memo[i] = memo[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        rMemo[i] = 1;
        for (int j = n - 1; i < j; j--)
        {
            // 현재 수(i번째)보다 다음 수가 더 작고
            // 기록이 안 되어 있다면
            if (arr[i] > arr[j] && rMemo[i] <= rMemo[j])
            {
                rMemo[i] = rMemo[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, memo[i] + rMemo[i] - 1);
    }

    return ans;
}

void input()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
