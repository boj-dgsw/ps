// math
// greedy
// Silver IV

#include <cstdio>
#include <cmath>

using ll = long long;

int main()
{
    int n;
    scanf("%d", &n);

    int half = 0;
    int fourth = 0;
    int three_quarter = 0;
    int ans = 0;

    while (n--)
    {
        int mole, deno;
        scanf("%d/%d", &mole, &deno);

        if (deno == 2)
            half++;

        else if (mole == 3)
            three_quarter++;

        else
            fourth++;
    }

    ans += three_quarter;
    ans += (half + 1) / 2;

    int leftover = three_quarter + 2 * (half % 2) - fourth;
    if (leftover < 0)
    {
        ans += abs(leftover) / 4 + (bool)(abs(leftover) % 4);
    }

    printf("%d", ans);
}
