// case work
// implementation
// Silver III

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

constexpr int CARD_COUNT(5);

unordered_map<char, vector<int>> cards_by_col;
unordered_map<int, unordered_multiset<char>> cards_by_num;
int r, b, y, g;

void input();
char find_most_counted_key();
bool is_continuous(const vector<int>& arr);
pair<int, int> cnt_minmax() { return minmax({ r, b, y, g }); }

int main()
{
    FAST_IO;
    input();

    int max_count = max({ r, b, y, g });

    // 조건 1, 4
    if (max_count == 5)
    {
        auto& same_col_cards = cards_by_col[find_most_counted_key()];
        ranges::sort(same_col_cards);

        // 조건 1
        if (is_continuous(same_col_cards))
        {
            cout << *ranges::max_element(same_col_cards) + 900;
        }
        // 조건 4
        else
        {
            cout << *ranges::max_element(same_col_cards) + 600;
        }

        return 0;
    }

    for (int i = 1; i <= 9; i++)
    {
        // 조건 2
        if (cards_by_num[i].size() == 4)
        {
            cout << i + 800;
            return 0;
        }

        // 조건 3, 6
        if (cards_by_num[i].size() == 3)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (i == j) continue;

                // 숫자가 같은 카드가 3장 + 2장임 (조건 3)
                if (cards_by_num[j].size() == 2)
                {
                    cout << i * 10 + j + 700;
                    return 0;
                }
            }

            // 숫자가 같은 카드가 3장, 1장, 1장임 (조건 6)
            cout << i + 400;
            return 0;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        // 조건 7, 8
        if (cards_by_num[i].size() == 2)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (i == j) continue;

                // 숫자가 같은 카드가 2장 + 2장임 (조건 7)
                if (cards_by_num[j].size() == 2)
                {
                    cout << max(i, j) * 10 + min(i, j) + 300;
                    return 0;
                }
            }

            // 숫자가 같은 카드가 2장임 (조건 8)
            cout << i + 200;
            return 0;
        }
    }

    vector<int> scores;
    for (const auto &same_col_cards_values: cards_by_col | views::values)
    {
        for (auto& val : same_col_cards_values)
        {
            scores.push_back(val);
        }
    }

    ranges::sort(scores);

    // 조건 5
    if (is_continuous(scores))
    {
        cout << scores.back() + 500;
    }
    // 조건 9
    else
    {
        cout << scores.back() + 100;
    }
}

bool is_continuous(const vector<int> &arr)
{
    int first_val = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != first_val + i)
            return false;
    }

    return true;
}

char find_most_counted_key()
{
    char most_counted_key('\0');
    int most_count = 0;

    const auto lol = cards_by_col['R'];
    for (const auto& card : cards_by_col)
    {
        if (most_count < card.second.size())
        {
            most_count = card.second.size();
            most_counted_key = card.first;
        }
    }

    return most_counted_key;
}

void input()
{
    for (int i = 0; i < CARD_COUNT; i++)
    {
        char col;
        int num;
        cin >> col >> num;

        cards_by_col[col].push_back(num);
        cards_by_num[num].emplace(col);
    }

    r = cards_by_col['R'].size();
    b = cards_by_col['B'].size();
    y = cards_by_col['Y'].size();
    g = cards_by_col['G'].size();
}
