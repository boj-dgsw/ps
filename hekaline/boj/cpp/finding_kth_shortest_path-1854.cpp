#include <iostream>
#include <queue>
#define OUT
#define PQ_INT_LESS priority_queue<int, vector<int>, less<>>

using namespace std;
constexpr int MAX = 0x3f3f3f3f;

struct Edge
{
    int end;
    int dist;
};

struct cmp
{
    bool operator()(const Edge& a, const Edge& b) const
    {
        return a.dist > b.dist;
    }
};

void dijkstra(const vector<vector<Edge>>& graph, OUT vector<PQ_INT_LESS>& distArr, int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    vector<PQ_INT_LESS> distArr;
    distArr.resize(n + 1);

    dijkstra(graph, distArr, k);

    for (int i = 1; i <= n; i++)
    {
        cout << (distArr[i].size() != k ? -1 : distArr[i].top()) << '\n';
    }
}

void dijkstra(const vector<vector<Edge>>& graph, OUT vector<PQ_INT_LESS>& distArr, int k)
{
    priority_queue<Edge, vector<Edge>, cmp> q;
    q.push({1, 0});
    distArr[1].push(0);

    while (!q.empty())
    {
        Edge currEdge = q.top(); q.pop();

        for (Edge nextEdge : graph[currEdge.end])
        {
            int nextDist = nextEdge.dist + currEdge.dist;
            if (distArr[nextEdge.end].size() < k)
            {
                distArr[nextEdge.end].push(nextDist);
                q.push({nextEdge.end, nextDist});
            } else if (distArr[nextEdge.end].top() > nextDist)
            {
                distArr[nextEdge.end].pop();
                distArr[nextEdge.end].push(nextDist);
                q.push({nextEdge.end, nextDist});
            }
        }
    }
}
