// mathematics
// sorting
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);

using namespace std;
using ll = long long;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    if (n % 2)
    {
        // n이 홀수
        cout << 1;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        int diff = a - b;
        arr[i] = diff;
    }

    ranges::sort(arr);
    cout << arr[n / 2] - arr[n / 2 - 1] + 1;
}
