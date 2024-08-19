#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n, m;
vector<int> dist;
vector<vector<int>> graph;

void search(vector<int>&& startFrom);
void input();

int main()
{
	FAST_IO;
	input();
	search({1});
	
	int q;
	cin >> q;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		
		if (a == b) continue;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
		
		search({a, b});
		
		for (int i = 1; i <= n; i++)
		{
			cout << (dist[i] == 100'001 ? -1 : dist[i]) << ' ';
		} cout << '\n';
	}
}

void search(vector<int>&& startFrom)
{
	queue<int> que;
	for (auto& e : startFrom)
	{
		que.emplace(e);
	}
	
	while (!que.empty())
	{
		int where = que.front(); que.pop();
		
		for (int const& next : graph[where])
		{
			if (dist[where] + 1 < dist[next])
			{
				dist[next] = dist[where] + 1;
				que.push(next);
			}
		}
	} // end of while
}

void input()
{
	cin >> n >> m;
	
	dist.resize(n + 1);
	graph.resize(n + 1);
	for (int i = 2; i <= n; i++)
	{
		dist[i] = 100'001;
	}
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (a == b) continue;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}
