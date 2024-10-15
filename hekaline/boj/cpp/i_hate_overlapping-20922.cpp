// two pointers
// Silver I

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

int main()
{
    FAST_IO

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> num_count;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left_ptr(0);
    int right_ptr(-1);
    int max_len = -1;

    do
    {
        if (num_count[arr[right_ptr + 1]] < k)
        {
            num_count[arr[right_ptr + 1]] += 1;
            right_ptr += 1;

            max_len = max(max_len, right_ptr - left_ptr + 1);
            // cout << '\n' << left_ptr << ' ' << right_ptr << '\n';
        } else
        {
            num_count[arr[left_ptr]] -= 1;
            left_ptr += 1;
        }
    } while (right_ptr < n - 1);

    cout << max_len;
}
