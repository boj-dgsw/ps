// mathematics
// number theory
// euclidean algorithm

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

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minDiff = abs(arr[0] - arr[1]);

    for (int i = 1; i < n - 1; i++)
    {
        minDiff = gcd(minDiff, abs(arr[i] - arr[i + 1]));
    }

    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(arr[i] - arr[i + 1]);

        if (gcd(diff, minDiff) == 1)
        {
            // 한 칸마다 나무를 배치해야 함
            cout << arr[n - 1] - arr[0] - n + 1;
            return 0;
        }
    }

    cout << (arr[n - 1] - arr[0]) / minDiff - n + 1;
}
