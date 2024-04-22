// 별자리 만들기: 2차원 상에 놓인 별을 모두 직/간접적으로 잇되, 선들의 길이 총합이 가장 짧은 것을 출력해야 함
// MST(최소 신장 트리): 별을 직/간접적으로 모두 가장 짧게 이어야 함
// 그래프 이론

#include <iostream>
#include <queue>
#include <cmath>
#include <map>

// C++ 스트림들이 C의 입출력과 동기화하지 않아 속도 향상
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using ld = long double;
struct Coord { ld x; ld y;};
struct Edge { int end; ld dist; };

struct cmp
{
  // 연산자 오버로딩 (pq가 비교를 하기 위해)
  // edge의 dist 기준으로 최소 힙을 만들게끔 한다.
	bool operator()(const Edge& a, const Edge& b) const
	{
		return a.dist > b.dist;
	}
};


void input();

/// <returns> prim 알고리즘을 사용해 MST의 총 길이를 반환합니다. </returns>
/// <param name="start"> 탐색 시작점 </params>
ld visit(int start);

// 두 점의 거리를 구한다.
ld getSqrt(ld x1, ld y1, ld x2, ld y2)
{
	ld x = abs(x1 - x2);
	ld y = abs(y1 - y2);

  // 피타고라스 정리 (root(x^2 + y^2))
	return sqrt(x * x + y * y);
}

// 간선을 거리 기준으로 담을 최소 힙
priority_queue<Edge, vector<Edge>, cmp> pq;

// 좌표 (index는 입력 순서대로)
vector<Coord> coordArr;

// 방문했는지 확인
vector<bool> visited;

// 별 개수
int n;

int main()
{
	FAST_IO;
	input();
	cout << visit(0) << '\n';
}

// 입력
void input()
{
	cin >> n;

  // 배열 크기 재할당
	coordArr.resize(n);
	visited.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		ld x, y;
		
		cin >> x >> y;
		coordArr[i] = {x, y};
	}
}

ld visit(int start)
{
  // 방문한 정점(별)의 개수를 뜻하며, n이 될 시(모든 정점 방문) result를 반환한다.
	int cnt = 0;
	ld result = 0;

  // 시작점을 처음 방문
	visited[start] = true;
	cnt += 1;

  // 시작점에 이어지는 간선을 만들고 pq에 넣는다.
	for (int i = 0; i < n; i++)
	{
    // 자기 자신 제외
		if (start == i) continue;

    // getSqrt(...): start 별에서 i번째 별까지의 길이
		pq.push({i, getSqrt(coordArr[start].x, coordArr[start].y, coordArr[i].x, coordArr[i].y)});
	}
  

  // 별을 모두 방문할 때까지
	while (cnt < n)
	{
    // 거리가 짧은 간선 순으로 방문한다.
		auto currEdge = pq.top(); pq.pop();
		auto currEnd = currEdge.end;
		auto currDist = currEdge.dist;

    // 이미 방문했으면 넘김
		if (visited[currEnd])
		{
			continue;
		}

    // 간선의 currEnd 방문
		visited[currEnd] = true;
     // 방문 카운트
		cnt += 1;

    // 간선 길이만큼 별자리의 총 거리를 더한다.
		result += currDist;

    // currEnd 별에서 방문하지 않은 다른 모든 별까지의 간선을 구한다.
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) continue;
			
			auto currCoord = coordArr[currEnd];
			auto nextCoord = coordArr[i];
			pq.push({i, getSqrt(currCoord.x, currCoord.y, nextCoord.x, nextCoord.y)});
		}
    
	} // end of while
	
	return result;
}
