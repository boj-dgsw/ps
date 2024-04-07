#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const int MAX = 10'001;

int dijkstra(
    const vector<vector<bool>>& graph,
    const pair<int, int>& start,
    const pair<int, int>& end
);

struct Edge
{
    pair<int, int> dest;
    ll weight;
};

struct cmp
{
    bool operator()(const Edge& a, const Edge& b)
    {
        return a.weight > b.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<bool>> graph;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(m);

        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++)
        {
            graph[i][j] = tmp[j] - '0';
        }
    }

    cout << dijkstra(graph, {0, 0}, {n - 1, m - 1});
}

int dijkstra(
    const vector<vector<bool>>& graph,
    const pair<int, int>& start,
    const pair<int, int>& end
)
{
    vector<vector<int>> distArr;
    distArr.resize(end.first + 1);
    for (int i = 0; i <= end.first; i++)
    {
        distArr[i].resize(end.second + 1);
        for (int j = 0; j <= end.second; j++)
        {
            distArr[i][j] = MAX;
        }
    }
    distArr[0][0] = 0;

    priority_queue<Edge, vector<Edge>, cmp> q;
    q.push({start, 0});

    while (!q.empty())
    {
        Edge currEdge = q.top(); q.pop();
        int currI = currEdge.dest.first;
        int currJ = currEdge.dest.second;

        pair<int, int> coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (pair<int, int> coord : coords)
        {
            int newI = currI + coord.first;
            int newJ = currJ + coord.second;

            if (newI < 0 || newJ < 0 || newI > end.first || newJ > end.second)
                continue;

            if (distArr[newI][newJ] > distArr[currI][currJ] + graph[newI][newJ])
            {
                distArr[newI][newJ] = distArr[currI][currJ] + graph[newI][newJ];
                q.push({{newI, newJ}, distArr[newI][newJ]});
            }
        }
    }

    return distArr[end.first][end.second];
}
