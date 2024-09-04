// Implementation
// Bronze I

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);

using namespace std;

constexpr int EMPTY = 0;

void input();

[[nodiscard]]
int getSum(int k, int l, int r);
void removeFlowers(int l, int r);

int n, q;
vector<int> arr;

int main()
{
    FAST_IO;
    input();

    while (q--)
    {
        int cmd, l, r;
        cin >> cmd >> l >> r;

        if (cmd == 1)
        {
            // print the count of k in index of l ~ r
            int k;
            cin >> k;

            cout << getSum(k, l, r) << '\n';
        } else // if (cmd == 2)
        {
            removeFlowers(l, r);
        }
    } // end of while
}

int getSum(const int k, const int l, const int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += (arr[i] == k);
    }

    return sum;
}

void removeFlowers(const int l, const int r)
{
    for (int i = l; i <= r; i++)
    {
        arr[i] = EMPTY;
    }
}

void input()
{
    int n;
    cin >> n;

    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;
}

