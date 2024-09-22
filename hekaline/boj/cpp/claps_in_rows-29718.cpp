// prefix sum
// sliding window
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO

    int n, m, a;
    cin >> n >> m;

    vector<int> arr(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;

            arr[j] += val;
        }
    }

    cin >> a;
    int sum = 0;

    for (int i = 0; i < a; i++)
    {
        sum += arr[i];
    }

    int maxSum = sum;

    for (int i = a; i < m; i++)
    {
        sum -= arr[i - a];
        sum += arr[i];

        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}
