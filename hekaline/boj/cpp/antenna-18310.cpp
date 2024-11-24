// implementation
// greedy
// Silver III

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
    for (int &val : arr)
    {
        cin >> val;
    }

    sort(arr.begin(), arr.end());

    int left = 0, right = 0;

    for (int &val : arr)
    {
        left += abs(arr[max(0, n / 2 - 1)] - val);
        right += abs(arr[n / 2] - val);
    }

    if (left <= right)
    {
        cout << arr[max(0, n / 2 - 1)];
    } else
    {
        cout << arr[n / 2];
    }
}
