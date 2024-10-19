#include <bits/stdc++.h>

using namespace std;

bool is_end(const int (&arr)[4]);
bool has_same_diff(const int (&arr)[4]);
void the_work(int (&arr)[4]);

int main()
{
    while (true)
    {
        int arr[4];
        for (int &val : arr)
            cin >> val;

        if (is_end(arr))
            break;

        int attempts = 0;
        do
        {
            if (has_same_diff(arr))
            {
                cout << attempts << '\n';
                break;
            }

            the_work(arr);
        } while (++attempts);
    }
}

void the_work(int (&arr)[4])
{
    int temp[4];
    for (int i = 0; i < 4 - 1; i++)
    {
        int diff = abs(arr[i] - arr[i + 1]);
        temp[i] = diff;
    }
    temp[3] = abs(arr[3] - arr[0]);

    copy(begin(temp), end(temp), begin(arr));
}


bool is_end(const int (&arr)[4])
{
    return all_of(begin(arr), end(arr),
        [](int i) { return i == 0; });
}

bool has_same_diff(const int (&arr)[4])
{
    return all_of(begin(arr), end(arr),
        [&](int i) { return i == arr[0]; });
}
