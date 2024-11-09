// segment tree
// lazyprop
// Platinum III

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr int XOR_RANGE = 1;
constexpr int PRINT_RANGE = 2;

int n, m;
vector<int> arr;
vector<int> tree;
vector<int> lazy;

void input();
void exec_queries();
void init_tree(int start, int end, int node);
void init_tree() { init_tree(1, n, 1); }

void update_lazy(int start, int end, int node);

void update(int left, int right, int start, int end, int node, int val);
void update(int left, int right, int val)
{ update(left, right, 1, n, 1, val); }

int get_ranged_xor(int left, int right, int start, int end, int node);
int get_ranged_xor(int left, int right)
{ return get_ranged_xor(left, right, 1, n, 1); }

void debug();

int main()
{
    FAST_IO;

    input();
    init_tree();
    exec_queries();
}

int get_ranged_xor(int left, int right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    const int mid = (start + end) / 2;
    return get_ranged_xor(left, right, start, mid, node * 2) ^
        get_ranged_xor(left, right, mid + 1, end, node * 2 + 1);
}


void update(int left, int right, int start, int end, int node, int val)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        const int length = (end - start) + 1;

        if (length % 2 == 1)
            tree[node] ^= val;

        if (start != end)
        {
            lazy[node * 2] ^= val;
            lazy[node * 2 + 1] ^= val;
        }

        return;
    }

    const int mid = (start + end) / 2;
    update(left, right, start, mid, node * 2, val);
    update(left, right, mid + 1, end, node * 2 + 1, val);

    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void update_lazy(int start, int end, int node)
{
    if (lazy[node] == 0) return;

    const int length = (end - start) + 1;

    if (length % 2 == 1)
        tree[node] ^= lazy[node];

    if (start != end)
    {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
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

    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

void exec_queries()
{
    while (m--)
    {
        int cmd, left, right;
        cin >> cmd >> left >> right;

        left++; right++;
        
        if (cmd == XOR_RANGE)
        {
            int val;
            cin >> val;

            update(left, right, val);
        }
        else // if (cmd == PRINT_RANGE)
        {
            cout << get_ranged_xor(left, right) << '\n';
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
    int i = 0;
    int max_i = 0;

    cout << "\ntree:\n";
    for (auto& e : tree)
    {
        cout << e << ' ';

        if (++i >= max_i)
        {
            i = 0;
            max_i = (max_i == 0 ? 1 : max_i * 2);

            cout << '\n';
        }
    }

    i = max_i = 0;

    cout << "\n\nlazy:\n";
    for (auto& e : lazy)
    {
        cout << e << ' ';

        if (++i >= max_i)
        {
            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;

            cout << '\n';
        }
    }

    cout << "\n\n";
}
