// lazyprop
// segment tree
// data structures
// Platinum IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

vector<int> tree;
vector<int> lazy;

void update_lazy(int start, int end, int node)
{
    if (lazy[node] == 0)
        return;

    tree[node] += lazy[node];

    if (start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

int get_value_at(int idx, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (idx < start || end < idx)
    {
        return 0;
    }

    if (idx == start && start == end)
    {
        int temp = tree[node];
        tree[node] = 0; // 이미 꽃이 핀 곳에는 더 피지 않음

        return temp;
    }

    const int mid = (start + end) / 2;

    return get_value_at(idx, start, mid, node * 2) +
        get_value_at(idx, mid + 1, end, node * 2 + 1);
}

void update(int left, int right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (right < left || right < start || end < left)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        // tree[node] += length;

        lazy[node] += 1;
        update_lazy(start, end, node);

        return;
    }

    const int mid = (start + end) / 2;

    update(left, right, start, mid, node * 2);
    update(left, right, mid + 1, end, node * 2 + 1);

    // tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void debug()
{
    int max_i = 0, i = 0;

    cout << "\n\ntree:\n";
    for (auto& val : tree)
    {
        cout << val << ' ';

        if (++i >= max_i)
        {
            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;

            cout << '\n';
        }
    }

    max_i = i = 0;

    cout << "\n\nlazy:\n";
    for (auto& val : lazy)
    {
        cout << val << ' ';

        if (++i >= max_i)
        {
            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;

            cout << '\n';
        }
    }

    cout << "\n\n";
}

int main()
{
    FAST_IO

    int n;
    cin >> n;

    tree.resize(400001);
    lazy.resize(400001);

    for (int i = 1; i <= n; i++)
    {
        int left, right;
        cin >> left >> right;

        cout << get_value_at(left, 1, 100000, 1) + get_value_at(right, 1, 100000, 1) << '\n';
        // debug();
        update(left + 1, right - 1, 1, 100000, 1);
        // debug();
    }
}
