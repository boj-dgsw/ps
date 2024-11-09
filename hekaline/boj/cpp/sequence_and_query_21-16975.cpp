// segment tree
// lazyprop
// Platinum IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using ll = long long;

constexpr int ADD_IN_SCOPE = 1;
constexpr int PRINT = 2;

int n, m;
vector<ll> arr;
vector<ll> tree;
vector<ll> lazy;

void input();
void init_tree(int start, int end, int node);
void init_tree() { init_tree(1, n, 1); }
void exec_queries();

void update_range(int left, int right, int start, int end, int node, ll val);
void update_range(int left, int right, ll val)
{ update_range(left, right, 1, n, 1, val); }

ll get_value_at(int idx, int start, int end, int node);
ll get_value_at(int idx)
{ return get_value_at(idx, 1, n, 1); }

void update_lazy(int start, int end, int node);
void debug();


int main()
{
    FAST_IO

    input();
    init_tree();
    exec_queries();
}

ll get_value_at(int idx, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (idx < start || end < idx)
    {
        return 0;
    }

    if (start == end && start == idx)
    {
        return tree[node];
    }

    const int mid = (start + end) / 2;

    return get_value_at(idx, start, mid, node * 2) +
        get_value_at(idx, mid + 1, end, node * 2 + 1);
}


void update_range(int left, int right, int start, int end, int node, const ll val)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        const int length = (end - start) + 1;
        tree[node] += val * length;

        if (start != end)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return;
    }

    const int mid = (start + end) / 2;
    update_range(left, right, start, mid, node * 2, val);
    update_range(left, right, mid + 1, end, node * 2 + 1, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int start, int end, int node)
{
    if (lazy[node] == 0) return;

    const ll length = (end - start) + 1;
    tree[node] += lazy[node] * length;

    if (start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}



void init_tree(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    const int mid = (start + end) / 2;
    init_tree(start, mid, node * 2);
    init_tree(mid + 1, end, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void exec_queries()
{
    while (m--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == ADD_IN_SCOPE)
        {
            int left, right;
            long long val;
            cin >> left >> right >> val;

            update_range(left, right, val);
        }
        else // if (cmd == PRINT)
        {
            int idx;
            cin >> idx;

            cout << get_value_at(idx) << '\n';
        }

        // debug();
    }
}


void input()
{
    cin >> n;
    arr.resize(n + 1);
    tree.resize(n * 4 + 10);
    lazy.resize(n * 4 + 10);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> m;
}

void debug()
{
    int i = 0, max_i = 0;

    cout << "\n\ntree:\n";

    for (auto& val : tree)
    {
        cout << val << ' ';

        if (++i >= max_i)
        {
            cout << '\n';

            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;
        }
    }

    i = max_i = 0;
    cout << "\n\nlazy:\n";

    for (auto& val : lazy)
    {
        cout << val << ' ';

        if (++i >= max_i)
        {
            cout << '\n';

            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;
        }
    }

    cout << "\n\n";
}
