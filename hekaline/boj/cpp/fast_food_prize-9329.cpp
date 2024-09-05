// implementation
// greedy algorithm
// Bronze I

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO\
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);

using namespace std;

int getMinStickerCount(vector<int>& stickers, vector<int>& neededStickers);

int main()
{
    FAST_IO;
    int t;
    cin >> t;

    while (t--)
    {
        int ans = 0;
        int n, m;
        cin >> n >> m;

        vector<vector<int>> neededStickers(n);
        vector<int> stickers(m + 1);

        for (int i = 0; i < n; i++)
        {
            int k; cin >> k;
            neededStickers[i].resize(k + 1);

            for (auto& sticker : neededStickers[i])
            {
                cin >> sticker;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            cin >> stickers[i];
        }

        for (int i = 0; i < n; i++)
        {
            int prize = neededStickers[i].back();
            int minVal = getMinStickerCount(stickers, neededStickers[i]);

            ans += prize * minVal;
        }

        cout << ans << '\n';
    }
}

int getMinStickerCount(vector<int> &stickers, vector<int> &neededStickers)
{
    int minVal = INT_MAX;

    // neededStickers[neededSticker.size() - 1] == prize
    for (int i = 0; i <= neededStickers.size() - 2; i++)
    {
        int neededSticker = neededStickers[i];
        minVal = min(minVal, stickers[neededSticker]);
    }

    return minVal;
}
