#include <cstdio>
#include <queue>
#define MAX 10'001

using namespace std;

short dijkstra(
    const vector<vector<bool>>& graph,
    const pair<short, short>& start,
    const pair<short, short>& end
);

struct Edge
{
    pair<short, short> dest;
    short weight;
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
    short m, n;
    scanf("%hd%hd",&m,&n);

    vector<vector<bool>> graph;
    graph.resize(n);
    for (short i = 0; i < n; i++)
    {
        graph[i].resize(m);

        for (short j = 0; j < m; j++)
        {
            short tmp; scanf("%1hd", &tmp);
            graph[i][j]=(bool)tmp;
        }
    }

    printf("%hd", dijkstra(graph, {0, 0}, {n - 1, m - 1}));
}

short dijkstra(
    const vector<vector<bool>>& graph,
    const pair<short, short>& start,
    const pair<short, short>& end
)
{
    vector<vector<short>> distArr;
    distArr.resize(end.first + 1);
    for (short i = 0; i <= end.first; i++)
    {
        distArr[i].resize(end.second + 1);
        for (short j = 0; j <= end.second; j++)
        {
            distArr[i][j] = MAX;
        }
    }
    distArr[0][0] = 0;

    priority_queue<Edge, vector<Edge>, cmp> q;
    q.push({start, 0});

    while (!q.empty())
    {
        const Edge currEdge = q.top(); q.pop();
        const short& currI = currEdge.dest.first;
        const short& currJ = currEdge.dest.second;

        pair<short, short> coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (const pair<short, short>& coord : coords)
        {
            short newI = currI + coord.first;
            short newJ = currJ + coord.second;

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
