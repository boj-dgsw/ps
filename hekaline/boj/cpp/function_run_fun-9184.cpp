// Dynamic Programming
// Recursion
// Silver II

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

vector<vector<vector<int>>> arr(51, vector<vector<int>>(51, vector<int>(51)));

int w(int a, int b, int c)
{
    if (a <= 0 or b <= 0 or c <= 0)
        return 1;

    if (arr[a][b][c] != 0) return arr[a][b][c];

    if (a > 20 or b > 20 or c > 20)
        return arr[a][b][c] = arr[20][20][20] = w(20, 20, 20);

    if (a < b and b < c)
        return arr[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    return arr[a][b][c] = w(a-1, b, c) +
        w(a-1, b-1, c) +
        w(a-1, b, c-1) -
        w(a-1, b-1, c-1);
}

int main()
{
    FAST_IO;
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 and b == -1 and c == -1)
            return 0;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}
