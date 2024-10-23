#include <bits/stdc++.h>

using namespace std;

int find_min(const vector<int> &arr);

int main()
{
    int n;
    cin >> n;

    vector<int> arr(26);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        arr[c - 'A'] += 1;
    }

    cout << find_min(arr);
}

int find_min(const vector<int> &arr)
{
    int res = INT_MAX;

    // E와 R을 제외한 비교 문자 (E와 R은 2개 포함됨)
    for (string cmp = "BONZSILV"; const char &c : cmp)
    {
        res = min(res, arr[c - 'A']);
    }

    // E와 R을 따로 비교
    res = min(res, arr['E' - 'A'] / 2);
    res = min(res, arr['R' - 'A'] / 2);

    return res;
}
