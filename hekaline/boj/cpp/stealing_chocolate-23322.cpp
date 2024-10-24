#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (auto& val : arr)
        cin >> val;

    int min_choco = arr[0];
    int max_stealing_choco = 0;
    int day = 0;

    for (auto& val : arr)
    {
        if (val == min_choco)
            continue;

        day += 1;
        max_stealing_choco += val - min_choco;
    }

    cout << max_stealing_choco << ' ' << day;
}
