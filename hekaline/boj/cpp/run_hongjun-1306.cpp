// Segment Tree
// Platinum V

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using ll = long long;

int n, m;
vector<int> arr;
vector<ll> tree;

void input();

ll init(int left, int right, int node);
ll query(int start, int end, int left, int right, int node);

int main()
{
    FAST_IO;
    input();
    init(1, n, 1);

    for (int i = m; i <= n - m + 1; i++)
    {
        cout << query(i - (m - 1), i + (m - 1), 1, n, 1) << '\n';
    }
}

ll init(int left, int right, int node)
{
    if (left == right) return tree[node] = arr[left];

    int mid = (left + right) / 2;
    return tree[node] = max(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

ll query(int start, int end, int left, int right, int node)
{
    if (end < left || right < start) return 0;
    if (start <= left && right <= end) return tree[node];

    int mid = (left + right) / 2;

    return max(query(start, end, left, mid, node * 2),
               query(start, end, mid + 1, right, node * 2 + 1));
}

void input()
{
    cin >> n >> m;

    arr.resize(n + 1);
    tree.resize(n * 4 + 4);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}
