// Bruteforcing

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef long double ld;

struct coord { ld x; ld y; };

// Pythagorean theorem
ld get_dist(const coord& a, const coord& b);
ld get_res(vector<coord>&);

int main()
{
    vector<coord> arr(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    cout << (int)get_res(arr);
}

bool same_exists(int numbers[])
{
    vector<int> check(3);
    for (int i = 0; i < 3; i++)
    {
        if (check[numbers[i]])
            return true;

        check[numbers[i]] = true;
    }

    delete[] numbers;
    return false;
}

ld get_res(vector<coord>& arr)
{
    ld smallest = 1000000.0;
    for (int j = 1; j < 4; j++)
        for (int k = 1; k < 4; k++)
            for (int l = 1; l < 4; l++)
            {
                if (same_exists(new int[3]{j, k, l}))
                {
                    continue;
                }


                smallest = min(smallest,
                               get_dist(arr[0], arr[j]) +
                               get_dist(arr[j], arr[k]) +
                               get_dist(arr[k], arr[l]));
            }

    return smallest;
}


ld get_dist(const coord& a, const coord& b)
{
    ld xDist = abs(a.x - b.x);
    ld yDist = abs(a.y - b.y);

    return sqrt(pow(xDist, 2) + pow(yDist, 2));
}
