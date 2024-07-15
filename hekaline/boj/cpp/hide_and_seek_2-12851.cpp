// BFS
// Graph

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, k;
int closest(100'001);
int ways;
int visited[100'001];

queue<int> q;
void bfs(int node);
bool isValid(int node)
{ return 0 <= node && node <= 100'000; }

int main()
{
	cin >> n >> k;
	
	bfs(n);
	cout << closest << '\n' << ways;
}

void bfs(int node)
{
	q.push(node);
	while (!q.empty())
	{
		int currNode = q.front();
		int dist = visited[currNode];
		q.pop();
		
		// cout << currNode << ' ' << dist << '\n';
		
		if (currNode == k)
		{
			closest = dist;
			ways += 1;
			
			continue;
		}
		
		int possibleWays[] = { currNode + 1, currNode - 1, currNode * 2 };
		for (int way : possibleWays)
		{
			if (!isValid(way)) continue;
			if (visited[way] == 0 || visited[way] == dist + 1)
			{
				visited[way] = dist + 1;
				q.push(way);
			}
		}
	}
}
