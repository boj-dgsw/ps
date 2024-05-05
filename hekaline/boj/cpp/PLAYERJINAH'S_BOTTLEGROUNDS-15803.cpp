// Geometry (기하학)
// Math

#include <iostream> // 입출력
#include <algorithm> // sort

using namespace std;
using ld = long double;

// 좌표 구조체
struct coord { ld x; ld y; };

// 왼쪽 위에 있는 팀원이 arr[0]에 가깝게 가도록 정렬하는 비교자
struct cmp
{
    bool operator()(const coord& a, const coord& b) const
    {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

int main()
{
    coord arr[3];
    for (auto& item : arr)
    {
        // 세 팀원의 위치 입력
        cin >> item.x >> item.y;
    }
    sort(arr, arr + 3, cmp());

    // 첫 번째 팀원과 두 번째 팀원의 거리 차이
    coord diff = {arr[0].x - arr[1].x, arr[0].y - arr[1].y};
    long double ratio = diff.y / diff.x; // x가 1 증가할 시 y 증가 (기울기)

    coord diff2 = {arr[1].x - arr[2].x, arr[1].y - arr[2].y};
    long double ratio2 = diff2.y / diff2.x; // 기울기 2

    if (ratio == ratio2)
    {
        // 직선상에 놓여 있다
        cout << "WHERE IS MY CHICKEN?";
        return 0;
    }

    // 직선이 아니므로 우승
    cout << "WINNER WINNER CHICKEN DINNER!";
}
