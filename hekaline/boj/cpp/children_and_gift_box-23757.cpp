// priority queue
// data structures
// Silver II

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<int> children(m);
    priority_queue<int, vector<int>, less<>> gifts;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        gifts.emplace(temp);
    }

    for (int &val : children)
    {
        cin >> val;
    }

    for (int &expected : children)
    {
        if (gifts.empty())
        {
            cout << 0;
            return 0;
        }

        int max_val = gifts.top();

        if (expected > max_val)
        {
            cout << 0;
            return 0;
        }

        gifts.pop();
        if (expected != max_val)
        {
            gifts.emplace(max_val - expected);
        }
    }

    cout << 1;
}
