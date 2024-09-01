// sort
// geometry
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using pii = pair<int, int>;

int len_pow(int x1, int y1, int x2, int y2)
{
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<pii> arr(4);


    for (int i = 0; i < n; i++)
    {
        vector<int> len;
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[j].first >> arr[j].second;
        }

        for (int j = 0; j < 4; j++)
        {
            for (int k = j + 1; k < 4; k++)
            {
                int lenPow = len_pow(arr[j].first, arr[j].second, arr[k].first, arr[k].second);
                len.push_back(lenPow);
            }
        }
        sort(len.begin(), len.end());

        bool isSquare = len[4] == len[5];
        if (isSquare)
        {
            for (int j = 0; j < 3; j++)
            {
                isSquare &= len[j] == len[j + 1];
            }
        }

        cout << isSquare << '\n';
    }
}
