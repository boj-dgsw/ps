// 그 유명한 TSP (외판원 순환 문제)임.
// 메모리를 아끼기 위해 visited를 비트필드로서 이용한다. 
// DFS와 유사하게 푸는 사람도 있다.

// 다이나믹 프로그래밍
// 비트마스킹
// 비트필드를 이용한 다이나믹 프로그래밍 (!)
// 외판원 순회 문제 (!)

#include <iostream>
#include <vector>
#define OUT

using namespace std;

constexpr int cantCycle = 17 * 1'000'000 + 1;
constexpr int notVisited = -1;

vector<vector<int>> w;
vector<vector<int>> shortest;
int n;

void input();
int tsp(int current, int visited);
int main()
{
	input();
	
	shortest[0][0] = 0;
	cout << tsp(0, 1);
}

int tsp(int current, int visited)
{
	// 전부 방문했는가?
	if (visited == (1 << n) - 1)
	{
		if (w[current][0] == 0)
		{
			// 현재 위치에서 처음 위치를 어디를 거쳐서든지 방문할 수가 없다면
			// (양방향이 아니어서 사이클 없을 수도 있음)
			return cantCycle;
		}
		
		// 처음으로 가는 길 비용 반환
		return w[current][0];
	}
	
	// 구해놓은 값이 있다면
	if (shortest[current][visited] != notVisited)
	{
		// 따로 구하지 않고 리턴
		return shortest[current][visited];
	}
	
	shortest[current][visited] = cantCycle * 2;
	for (int nextCity = 0; nextCity < n; nextCity++)
	{
		// 0이 아니어야 방문할 수 있음
		if (w[current][nextCity] == 0) continue;
		
		// visited에서 도시를 이미 방문했다고 되어 있으면 넘김
		if ((visited & (1 << nextCity)) != 0) continue;
		
		// 지금까지 기록한 current에서 visited로 가는 길보다 더 빠른 길이 나온다면 갱신해야 함
		// tsp(nextCity, visited): 현재 tsp의 방문하지 않은 리스트를 다른 도시가 그대로 방문한 것의 제일 짧은 거리
		shortest[current][visited] = min(
				shortest[current][visited],
				tsp(nextCity, visited | (1 << nextCity)) + w[current][nextCity]);
	}
	
	return shortest[current][visited];
}

void input()
{
	cin >> n;
	
	w.resize(n);
	shortest.resize(n);
	for (int i = 0; i < n; i++)
	{
		w[i].resize(n);
		shortest[i].resize(1 << n);
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
//		for (int j = 0; j < (1 << n); j++)
//		{
//			shortest[i][j] = notVisited;
//		}
		fill_n(shortest[i].begin(), shortest[i].size(), notVisited);
	}
}
