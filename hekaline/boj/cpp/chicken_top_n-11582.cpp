// sort
// Silver IV

#include <bits/stdc++.h>
#define FAST_IO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

using namespace std;

void input();
void sort_arr(int left, int right, int count);

int n, k;
vector<int> arr;

int main()
{
    FAST_IO

    input();
    sort_arr(0, n - 1, n / k);

    for (const int& val : arr)
        cout << val << ' ';
}

void sort_arr(int left, int right, int count)
{
    for (int i = left; i < right; i += count)
    {
        sort(&arr[i], &arr[i + count]);
    }
}


void input()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
}
