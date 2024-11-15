// sort
// implementation
// Silver IV

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(m * 2);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[(i - 1) * 2].first = a;
        arr[(i - 1) * 2 + 1].first = b;

        arr[(i - 1) * 2].second = i;
        arr[(i - 1) * 2 + 1].second = i;
    }

    ranges::sort(arr);

    cout << arr[(n - 1) % (m * 2)].second;
}
