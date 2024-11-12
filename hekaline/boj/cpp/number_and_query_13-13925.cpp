// segment tree
// lazyprop
// data structure
// Platinum I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using ll = long long;

constexpr int MOD = 1e9+7;
constexpr char ADD_RANGE = 1;
constexpr char MUL_RANGE = 2; // 곱할 때 overflow 가능성 있음
constexpr char REPLACE = 3;
constexpr char PRINT_RANGE = 4;

int n, m;
vector<int> arr;
vector<int> tree;
vector<pair<int, int>> lazy; // { mul, sum }

void input();
void exec_queries();
void init_tree(int start, int end, int node);
void init_tree()
{ init_tree(1, n, 1); }

void update(int &left, int &right, int start, int end, int node, int mul, int sum);
void update(int &left, int &right, int mul, int sum)
{ update(left, right, 1, n, 1, mul, sum); }
void update_lazy(int start, int end, int node);

int get_prefix_sum(int &left, int &right, int start, int end, int node);
int get_prefix_sum(int &left, int &right)
{ return get_prefix_sum(left, right, 1, n, 1); }

void debug();

int main()
{
    FAST_IO

    input();
    init_tree();
    exec_queries();
}

int get_prefix_sum(int &left, int &right, int start, int end, int node)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node] % MOD;
    }

    const int mid = (start + end) / 2;
    return (get_prefix_sum(left, right, start, mid, node * 2) % MOD +
        get_prefix_sum(left, right, mid + 1, end, node * 2 + 1) % MOD) % MOD;
}


void update(int &left, int &right, int start, int end, int node, int mul, int sum)
{
    update_lazy(start, end, node);

    if (end < left || right < start)
    {
        return;
    }

    if (left <= start && end <= right)
    {
        lazy[node].first = ((ll)lazy[node].first * (ll)mul) % MOD;
        lazy[node].second = (((ll)lazy[node].second * (ll)mul) % MOD + sum) % MOD;

        // update tree[node]
        update_lazy(start, end, node);
        return;
    }


    const int mid = (start + end) / 2;
    update(left, right, start, mid, node * 2, mul, sum);
    update(left, right, mid + 1, end, node * 2 + 1, mul, sum);

    tree[node] = (tree[node * 2] % MOD + tree[node * 2 + 1] % MOD) % MOD;
}


void update_lazy(int start, int end, int node)
{
    auto &[mul, sum] = lazy[node];
    if (mul == 1 && sum == 0)
        return;

    bool is_leap = start == end;
    int length = end - start + 1;

    // update tree
    tree[node] = ((ll)tree[node] * (ll)mul) % MOD;
    tree[node] = (tree[node] + ((ll)sum * (ll)length) % MOD) % MOD;

    if (!is_leap)
    {
        // update children lazy
        lazy[node * 2].first = ((ll)lazy[node * 2].first * (ll)mul) % MOD;
        lazy[node * 2 + 1].first = ((ll)lazy[node * 2 + 1].first * (ll)mul) % MOD;

        lazy[node * 2].second = (((ll)lazy[node * 2].second * (ll)mul) % MOD + sum) % MOD;
        lazy[node * 2 + 1].second = (((ll)lazy[node * 2 + 1].second * (ll)mul) % MOD + sum) % MOD;
    }

    mul = 1;
    sum = 0;
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

    tree[node] = (tree[node * 2] % MOD + tree[node * 2 + 1] % MOD) % MOD;
}

void exec_queries()
{
    while (m--)
    {
        int cmd, left, right;
        cin >> cmd >> left >> right;

        if (cmd <= REPLACE)
        {
            int val;
            cin >> val;
            val %= MOD;

            switch (cmd)
            {
                case ADD_RANGE:
                    update(left, right, 1, val);
                break;
                case MUL_RANGE:
                    update(left, right, val, 0);
                break;
                case REPLACE:
                    update(left, right, 0, val);
                break;

                default: break;
            }

            debug();
        }
        else // if (cmd == PRINT_RANGE)
        {
            cout << get_prefix_sum(left, right) << '\n';
        }
    }
}


void input()
{
    cin >> n;
    arr.resize(n + 1);
    tree.resize(n * 4 + 1);
    lazy.resize(n * 4 + 1, {1, 0});

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] %= MOD;
    }

    cin >> m;
}

void debug()
{
    int i = 0, max_i = 0;

    cout << "\n\ntree: \n";
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

    cout << "\n\nlazy: \n";

    i = max_i = 0;

    for (auto& val : lazy)
    {
        cout << "{ " << val.first << ", " << val.second << " }" << ' ';

        if (++i >= max_i)
        {
            i = 0;
            max_i = max_i == 0 ? 1 : max_i * 2;

            cout << '\n';
        }
    }

    cout << "\n\n";
}
