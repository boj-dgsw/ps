#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int n, m;
vector<int> music_irl;
vector<int> music_in_dream;

void input();
pair<int, int> get_answer();

int main()
{
    FAST_IO;
    input();

    auto [fst, snd] = get_answer();
    if (fst == INT_MAX && snd == INT_MIN)
    {
        cout << -1;
        return 0;
    }

    cout << fst << ' ' << snd;
}

void input()
{
    cin >> n;
    music_irl.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> music_irl[i];
    }

    cin >> m;
    music_in_dream.resize(m);

    for (int i = 0; i < m; i++)
    {
        cin >> music_in_dream[i];
    }
}

pair<int, int> get_answer()
{
    pair ans { INT_MAX, INT_MIN };

    for (int i = 0; i <= m - n; i++)
    {
        if (music_in_dream[i] != music_irl[0])
            continue;

        for (int j = i + 1; j < m; j++)
        {
            if (music_in_dream[j] != music_irl[1])
                continue;

            int sound_left = n - 2;
            int jump_len = j - i;


            for (int k = 2; k <= n; k++)
            {
                int curr_idx = i + jump_len * k;

                if (curr_idx >= m)
                    break;

                if (music_irl[k] != music_in_dream[curr_idx])
                    break;

                sound_left -= 1;
            }

            if (sound_left <= 0)
            {
                ans.first = min(ans.first, jump_len - 1);
                ans.second = max(ans.second, jump_len - 1);
            }
        }
    }

    return ans;
}
