// Greedy
// Sorting
// Silver IV

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using pii = pair<int, int>;

struct cmp
{
    bool operator()(const pii& a, const pii& b)
    {
        return a.first < b.first;
    }
};

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<pii> arr_a(n);
    vector<int> arr_b(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr_a[i].first;
        arr_a[i].second = i;
    }

    for (auto& e : arr_b)
    {
        cin >> e;
    }

    ranges::sort(arr_a, cmp());
    ranges::sort(arr_b);

    for (int i = 0; i < n; i++)
    {
        if (arr_a[i].first <= arr_b[i])
        {
            ans[arr_a[i].second] = arr_b[i];
            continue;
        }

        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}
