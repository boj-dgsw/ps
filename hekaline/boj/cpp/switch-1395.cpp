// segment tree
// lazyprop
// Platinum III

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr int REVERSE = 0;
constexpr int QUERY = 1;

int n, m;
vector<int> tree;
vector<bool> lazy;

void input();
void reverse_switches(int left, int right, int start, int end, int node);
void reverse_switches(int left, int right)
{ reverse_switches(left, right, 1, n, 1); }
int get_count(int left, int right, int start, int end, int node);
int get_count(int left, int right)
{ return get_count(left, right, 1, n, 1); }
void update_lazy(int start, int end, int node);

int main()
{
    FAST_IO
    input();
}

int get_count(int left, int right, int start, int end, int node)
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
    return get_count(left, right, start, mid, node * 2) +
        get_count(left, right, mid + 1, end, node * 2 + 1);
}


void reverse_switches(int left, int right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        const int length = (end - start) + 1;
        tree[node] = length - tree[node];

        if (start != end)
        {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }

        return;
    }

    const int mid = (start + end) / 2;
    reverse_switches(left, right, start, mid, node * 2);
    reverse_switches(left, right, mid + 1, end, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_lazy(int start, int end, int node)
{
    if (lazy[node] == false)
    {
        return;
    }

    const int length = (end - start) + 1;
    tree[node] = length - tree[node];

    if (start != end)
    {
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
    }

    lazy[node] = false;
}


void input()
{
    cin >> n >> m;

    tree.resize(n * 4 + 10);
    lazy.resize(n * 4 + 10);

    while (m--)
    {
        int cmd, left, right;
        cin >> cmd >> left >> right;

        if (cmd == REVERSE)
        {
            reverse_switches(left, right);
        }
        else // if (cmd == QUERY)
        {
            cout << get_count(left, right) << '\n';
        }
    }
}
