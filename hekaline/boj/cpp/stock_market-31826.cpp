// Implementation
// Simulation
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int stocks[601];

int hashf(int n)
{
    n /= 10;
    return n - 700;
}

int unhashf(int hashed_n)
{
    hashed_n += 700;
    return hashed_n * 10;
}

int main()
{
    FAST_IO;
    int q;
    cin >> q;

    int curr = 10000;
    while (q--)
    {
        int p, x, f;
        cin >> p >> x >> f;

        p = hashf(p);
        if (f == 1)
        {
            // 구매

            // 원래 판매 물량이 있었을 경우
            if (stocks[p] < 0)
            {
                curr = unhashf(p);
            }
            stocks[p] += x;
        } else // if (f == -1)
        {
            // 판매

            // 원래 구매 물량이 있었을 경우
            if (stocks[p] > 0)
            {
                curr = unhashf(p);
            }
            stocks[p] -= x;
        }
    }

    cout << curr;
}
