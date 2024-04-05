#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;


struct Edge
{
	ll dest;
	ll weight;

	Edge(ll _dest, ll _weight) :
		dest(_dest), weight(_weight) {}
};

ll minDist[50'001];
vector<Edge> graph[50'001];

void init();

/// <returns> Distance between start and end. </returns>
int dijkstra(int end);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	init();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		ll start, end, weight;
		cin >> start >> end >> weight;

		graph[start].push_back(Edge(end, weight));
		graph[end].push_back(Edge(start, weight));
	}

	cout << dijkstra(n);
}

int dijkstra(int end)
{
	queue<Edge> q; // dest, val
	q.push({ 1, 0 });
	minDist[1] = 0;

	while (!q.empty())
	{
		Edge currEdge = q.front();
		q.pop();

		for (Edge connectedEdge : graph[currEdge.dest])
		{
			if (minDist[connectedEdge.dest] > minDist[currEdge.dest] + connectedEdge.weight)
			{
				minDist[connectedEdge.dest] = minDist[currEdge.dest] + connectedEdge.weight;
				q.push({ connectedEdge.dest, minDist[connectedEdge.dest] });
			}
			
		}
	}

	return minDist[end];
}

void init()
{
	for (int i = 0; i < 50'001; i++)
	{
		minDist[i] = 0x3f3f3f3f;
	}
}
