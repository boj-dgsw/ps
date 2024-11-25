// bruteforcing
// backtrack
// Silver III

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int n;
vector<bool> visited(8);
vector<int> seq;

void backtrack(int cnt)
{
    if (cnt == n)
    {
        for (int& val : seq)
        {
            cout << val << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            seq.emplace_back(i + 1);
            backtrack(cnt + 1);
            seq.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    FAST_IO
    cin >> n;

    backtrack(0);
}
