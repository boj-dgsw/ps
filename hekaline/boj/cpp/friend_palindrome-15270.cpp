// backtrack
// bruteforce
// graph theory
// graph search
// dfs
// Silver I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using PII = pair<int, int>;

int n, m, ans = 1;
vector<PII> friends;
vector<bool> visited;
list<int> line;

void input();
void foo(int idx, int count);

int main()
{
    FAST_IO;
    input();

    foo(0, 0);
    cout << ans;
}

void foo(int idx, int count)
{
    if (count + 1 >= n)
    {
        cout << n;
        exit(0);
    }

    ans = max(ans, count);
    if (ans % 2 == 0)
    {
        ans += 1;
    }

    int size = friends.size();
    for (int i = idx; i < size; i++)
    {
        PII& _pair = friends[i];

        if (visited[_pair.first] || visited[_pair.second])
            continue;

        visited[_pair.first] = visited[_pair.second] = true;
        foo(i + 1, count + 2);
        visited[_pair.first] = visited[_pair.second] = false;
    }
}


void input()
{
    cin >> n >> m;
    friends.resize(m);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        friends[i] = {u, v};
    }
}
