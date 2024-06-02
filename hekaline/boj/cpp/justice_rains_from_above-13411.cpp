// Silver IV
// Geometry

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

// 빠른 입출력
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

// 미사일 (도착 시간, 번호)
struct missile { double timeOfArrival; int num; };

// PQ 비교 연산자 정의
// 도착 시간이 짧은 것 우선, 시간이 같다면 숫자가 작은 것 우선
struct cmp
{
    bool operator()(const missile& a, const missile& b) const
    {
        return a.timeOfArrival > b.timeOfArrival ||
            a.timeOfArrival == b.timeOfArrival && a.num > b.num;
    }
};

// 비교 연산자를 사용한 pq 정의
// 시간 오름차순으로 출력하기 위해 pq 사용
priority_queue<missile, vector<missile>, cmp> pq;

// 입력
void input();

// pq가 빌 때까지 모두 출력
void popPq() { while (!pq.empty()) { cout << pq.top().num << '\n'; pq.pop(); } }

// 피타고라스 정리
double dist(int x, int y)
{ return sqrt(pow(x, 2) + pow(y, 2)); }

int main()
{
    FAST_IO;
    
    input();
    popPq();
}

void input()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;

        // 도착 시간: 거리 / 속도
        pq.push({dist(x, y) / (double)v, i + 1});
    }
}
