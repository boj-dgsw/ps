// Geometry

#include <iostream>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

class Coord
{
public:
    int x; int y;
    Coord(int _x, int _y) : x(_x), y(_y) {}
    Coord() : x(0), y(0) {}
};

class Rectangle
{
public:
    Coord lowerL = Coord(0, 0);
    Coord upperR = Coord(0, 0);

    Rectangle() : lowerL(0, 0), upperR(0, 0) {}
    explicit Rectangle(const int* arr) :
        lowerL(arr[0], arr[1]), upperR(arr[2], arr[3]) {}

    int get_area() const
    {
        return (upperR.x - lowerL.x) * (upperR.y - lowerL.y);
    }
};

int GetAnswer(const Rectangle& origin, const Rectangle& cover);

int main()
{
    FAST_IO;

    int temp[4];
    for_each(temp, temp+4, [](int& e)
    {
        cin >> e;
    }); Rectangle lawnmower(temp);

    for_each(temp, temp+4, [](int& e)
    {
        cin >> e;
    }); Rectangle cowFeed(temp);

    cout << GetAnswer(lawnmower, cowFeed);
}

int GetAnswer(const Rectangle& origin, const Rectangle& cover)
{
    Rectangle res = origin;

    // if horizontally covered
    if (cover.lowerL.x <= origin.lowerL.x && cover.upperR.x >= origin.upperR.x)
    {
        // if upper side covered
        if (cover.lowerL.y < origin.upperR.y && cover.upperR.y >= origin.upperR.y)
            res.upperR.y = cover.lowerL.y;
        // if lower side covered
        if (cover.upperR.y > origin.lowerL.y && cover.lowerL.y <= origin.lowerL.y)
            res.lowerL.y = cover.upperR.y;
    }

    // if vertically covered
    if (cover.lowerL.y <= origin.lowerL.y && cover.upperR.y >= origin.upperR.y)
    {
        // if left side covered
        if (cover.lowerL.x <= origin.lowerL.x && cover.upperR.x > origin.lowerL.x)
            res.lowerL.x = cover.upperR.x;
        // if right side covered
        if (cover.lowerL.x < origin.upperR.x && cover.upperR.x >= origin.upperR.x)
            res.upperR.x = cover.lowerL.x;
    }

    return res.get_area();
}
