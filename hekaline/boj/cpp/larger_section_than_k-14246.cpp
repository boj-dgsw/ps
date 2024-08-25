// Two pointers
// Silver II

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    long long sum = arr[0];
    long long ans = 0;
    int left = 0;
    int right = 0;

    while (true)
    {
        if (sum > k)
        {
            ans += n - right;

            sum -= arr[left++];
            if (left >= n) break;
        }
        else
        {
            if (right + 1 >= n) break;
            sum += arr[++right];
        }
    }

    cout << ans;
}
