#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MAX = 987654321;

struct Edge
{
    ll dest;
    ll time;

    Edge(ll _dest, ll _time) :
        dest(_dest), time(_time) { }
};

struct Greater
{
    bool operator()(Edge a, Edge b)
    {
        return a.time > b.time;
    }
};

pair<ll, ll> solve();

/// <returns> Distance between start and end. </returns>
vector<ll> dijkstra(int start, const vector<vector<Edge>>& graph);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tn; cin >> tn; // test number

    while (tn--)
    {
        auto ans = solve();
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

pair<ll, ll> solve()
{
    int n, d, c;
    cin >> n >> d >> c;

    vector<vector<Edge>> graph;
    graph.resize(n + 1);

    for (int i = 0; i < d; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;

        graph[b].push_back({ a, s });
    }

    auto minTimeArr = dijkstra(c, graph);
    int cnt = 0;
    ll maxTime = 0;
    for (auto e : minTimeArr)
    {
        if (e != MAX)
        {
            cnt += 1;
            maxTime = max(maxTime, e);
        }
    }

    return { cnt, maxTime };
}

vector<ll> dijkstra(int start, const vector<vector<Edge>>& graph)
{
    vector<ll> minTimeArr;
    int arrSize = graph.size();
    minTimeArr.resize(arrSize + 1);

    for (int i = 0; i <= arrSize; i++)
    {
        minTimeArr[i] = MAX;
    }
    minTimeArr[start] = 0;

    priority_queue<Edge, vector<Edge>, Greater> q;
    q.push(Edge(start, 0));

    while (!q.empty())
    {
        Edge currEdge = q.top(); q.pop();
        if (minTimeArr[currEdge.dest] < currEdge.time) continue;

        for (Edge connectedEdge : graph[currEdge.dest])
        {
            if (minTimeArr[connectedEdge.dest] > minTimeArr[currEdge.dest] + connectedEdge.time)
            {
                minTimeArr[connectedEdge.dest] = minTimeArr[currEdge.dest] + connectedEdge.time;
                q.push({ connectedEdge.dest, minTimeArr[connectedEdge.dest] });
            }
        }
    }

    return minTimeArr;
}

