// Silver III
// Binary Search

#include <iostream>

using namespace std;

long long x, y;
long long res;
void bSearch(int percent, long long start, long long end);

int main()
{
    cin >> x >> y;

    int z = y * 100 / x;
    if (z >= 99)
    {
        cout << -1;
        return 0;
    }

    res = x;
    bSearch(z, 0, x);
    cout << res;
}

void bSearch(int percent, long long start, long long end)
{
    if (start > end) return;
    long long mid = (start + end) / 2;

    long long tempX = x + mid;
    long long tempY = y + mid;
    long long tempZ = tempY * 100 / tempX;

    if (percent < tempZ)
    {
        res = mid;
        bSearch(percent, start, mid - 1);
    } else
    {
        bSearch(percent, mid + 1, end);
    }
}
