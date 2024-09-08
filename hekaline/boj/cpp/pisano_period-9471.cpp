// number theory
// bruteforcing
// mathematics
// Silver IV

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int p;
    cin >> p;

    while (p--)
    {
        int n, m;
        cin >> n >> m;

        cout << n << ' ';

        int left = 1, right = 1;
        for (int i = 1; i <= 500010; i++)
        {
            int tmp = left + right;
            left = right % m;
            right = tmp % m;

            if (left == 1 && right == 1)
            {
                cout << i << '\n';
                break;
            }
        }
    }
}
