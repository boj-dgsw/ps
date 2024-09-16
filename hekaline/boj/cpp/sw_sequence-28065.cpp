// Constructive
// Silver IV

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;
    int n;
    cin >> n;

    cout << n << " 1 ";
    int prev = 1;
    bool isRising = true;

    for (int i = n - 2; i >= 1; i--)
    {
        prev = isRising ? prev + i : prev - i;
        isRising = !isRising;
        cout << prev << ' ';
    }
}
