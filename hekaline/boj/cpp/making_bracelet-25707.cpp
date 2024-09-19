// Ad-hoc
// Mathematics
// greedy
// Silver V

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        minVal = min(minVal, temp);
        maxVal = max(maxVal, temp);
    }

    cout << (maxVal - minVal) * 2;
}
