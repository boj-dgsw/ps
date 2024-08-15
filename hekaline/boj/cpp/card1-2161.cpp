#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.emplace(i);
    }

    bool bCanDiscard = true;
    while (!q.empty())
    {
        int element = q.front(); q.pop();
        if (bCanDiscard)
        {
            bCanDiscard = false;
            cout << element << ' ';
        } else
        {
            bCanDiscard = true;
            q.emplace(element);
        }
    }
}
