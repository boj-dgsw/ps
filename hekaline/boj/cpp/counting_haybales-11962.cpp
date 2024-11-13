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
using ll = long long;

constexpr char PRINT_MIN = 'M';
constexpr char UPDATE = 'P';
constexpr char PRINT_SUM = 'S';

int n, q;
vector<ll> arr;
vector<pair<ll, ll>> tree; // { sum, min }
vector<ll> lazy;

void input();
void exec_queries();

void init_tree(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = { arr[start], arr[start] };
        return;
    }

    const int mid = (start + end) / 2;
    init_tree(start, mid, node * 2);
    init_tree(mid + 1, end, node * 2 + 1);

    tree[node] = { tree[node * 2].first + tree[node * 2 + 1].first,
        min(tree[node * 2].second, tree[node * 2 + 1].second) };
}

void update_lazy(int start, int end, int node)
{
    if (lazy[node] == 0)
        return;

    const int length = (end - start) + 1;
    tree[node].first += lazy[node] * length;
    tree[node].second += lazy[node];

    if (start != end)
    {
        // not leap node

        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int left, int right, int start, int end, int node, ll val)
{
    update_lazy(start, end, node);

    if (right < start || end < left)
    {
        // out of range
        return;
    }

    if (left <= start && end <= right)
    {
        const int length = (end - start) + 1;

        lazy[node] += val;
        update_lazy(start, end, node);

        return;
    }

    const int mid = (start + end) / 2;
    update(left, right, start, mid, node * 2, val);
    update(left, right, mid + 1, end, node * 2 + 1, val);

    tree[node] = { tree[node * 2].first + tree[node * 2 + 1].first,
        min(tree[node * 2].second, tree[node * 2 + 1].second) };
}

ll get_min_value(int left, int right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (right < start || end < left)
    {
        // out of range
        return LLONG_MAX;
    }

    if (left <= start && end <= right)
    {
        return tree[node].second;
    }

    const int mid = (start + end) / 2;
    return min(get_min_value(left, right, start, mid, node * 2),
        get_min_value(left, right, mid + 1, end, node * 2 + 1));
}

ll get_sum(int left, int right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (right < start || end < left)
    {
        // out of range
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node].first;
    }

    const int mid = (start + end) / 2;
    return get_sum(left, right, start, mid, node * 2) +
        get_sum(left, right, mid + 1, end, node * 2 + 1);
}

int main()
{
    FAST_IO;

    input();
    init_tree(1, n, 1);
    exec_queries();
}

void exec_queries()
{
    while (q--)
    {
        char cmd;
        int left, right;
        cin >> cmd >> left >> right;

        if (cmd == UPDATE)
        {
            ll val;
            cin >> val;

            update(left, right, 1, n, 1, val);
        }
        else if (cmd == PRINT_MIN)
        {
            cout << get_min_value(left, right, 1, n, 1) << '\n';
        }
        else // if (cmd == PRINT_SUM)
        {
            cout << get_sum(left, right, 1, n, 1) << '\n';
        }
    }
}


void input()
{
    cin >> n >> q;

    arr.resize(n + 1);
    tree.resize(n * 4 + 1);
    lazy.resize(n * 4 + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}
