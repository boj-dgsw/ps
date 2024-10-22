#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;
using PII = pair<int, int>;

int n;
vector<PII> schedules; // { start, end }

void input();
int get_ans();
istream& operator>>(istream& is, PII& target);

int main()
{
    FAST_IO;
    input();

    cout << get_ans();
}

int get_ans()
{
    int res = 0;
    vector<int> heights(365 + 1);

    for (auto &[start, end] : schedules)
    {
        int max_height = 0;
        for (int i = start; i <= end; i++)
        {
            heights[i] += 1;
        }
    }

    int i = 1;
    while (i <= 365)
    {
        // 최소 하나의 일정이 존재하는가?
        if (heights[i] != 0)
        {
            // 이 일정과 떨어져있지 않은(직접 혹은 다른 일정을 통해 연결된) 날들 중 가장 높은 높이
            int max_height = heights[i];
            int streak = 1;
            while (i + 1 <= 365 && heights[i + 1] != 0)
            {
                i++;
                streak++;

                max_height = max(max_height, heights[i]);
            }

            // 연결된 길이 * 최대 높이 곱하기
            res += streak * max_height;
        }

        i++;
    }

    // for (int j = 1; j <= 12; j++)
    // {
    //     cout << max_heights[j] << ' ';
    // } cout << endl;
    return res;
}

void input()
{
    cin >> n;
    schedules.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> schedules[i];
    }
}

istream& operator>>(istream& is, PII& target)
{
    is >> target.first >> target.second;
    return is;
}
