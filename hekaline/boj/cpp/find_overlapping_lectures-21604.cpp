// ad-hoc
// constructive
// Silver V

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

    vector arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << m << '\n';
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[(i + j) % m][j] << ' ';
        } cout << '\n';
    }
}
