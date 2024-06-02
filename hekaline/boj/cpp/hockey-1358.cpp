// geometry
// pytagorean
// Silver IV

#include <iostream>
#include <cmath>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

double w, h, x, y, p;
double r;
int res;

void input();
bool isInRink(int targetX, int targetY);

int main()
{
    FAST_IO;

    input();
    cout << res;
}

bool isInRink(int targetX, int targetY)
{
    // in square
    if (x <= targetX && targetX <= x + w && y <= targetY && targetY <= y + h)
    {
        return true;
    }

    double xRange(0), yRange, range;
    
    // y range from (?, y+radius)
    yRange = abs(targetY - (y + r));
    // left semicircle
    if (targetX <= x)
    {
        // x range from (x, y+radius)
        xRange = abs(targetX - x);
    }

    // right semicircle
    if (targetX >= x + w)
    {
        // x range from (x+width, y+radius)
        xRange = abs(targetX - (x + w));
    }

    // Pythagorean theorem
    range = sqrt(pow(xRange, 2) + pow(yRange, 2));

    // point in semicircle?
    return range <= r;
}

void input()
{
    cin >> w >> h >> x >> y >> p;
    r = h / 2.;

    for (int i = 0; i < p; i++)
    {
        int targetX, targetY;
        cin >> targetX >> targetY;

        res += isInRink(targetX, targetY);
    }
}
