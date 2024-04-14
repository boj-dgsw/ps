#include <iostream>
#include <vector>
#include <queue>

// 코드에 아무 영향을 끼치지 않지만 파라미터 값이 바뀔 수 있음을 알려주는 매크로이다.
#define OUT

// sync_with_stdio가 false라면 (C 입출력과 동기화하지 않는다면) 
// 표준 C++ 스트림들은 각각의 입출력 연산에 대해 버퍼를 사용할 수 있는데,
// 이 경우 입출력 연산 속도를 크게 향상 시킬 수 있다. 
#define FAST_IO ios_base::sync_with_stdio(false);\
                cin.tie(nullptr);\
                cout.tie(nullptr);

using namespace std;

/// 전방 선언 ///
struct Edge;
void dijkstra(const vector<vector<Edge>>& graph, int start, OUT vector<int>& minDistArr);
/// 전방 선언 끝 ///

// 끝 정점과 거리를 표현하는 Edge 구조체
struct Edge
{
    int end;
    int dist;
};

// 우선순위 큐의 삽입(enqueue(push)) 기준이 되는 비교 구조체
struct cmp
{
    bool operator()(const Edge& a, const Edge& b) const
    {
         return a.dist > b.dist;
    }
};

int main()
{
    FAST_IO;

    /////// 입력 시작 ///////

    // 정점 및 간선 개수 입력받기
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    // 그래프 2중 벡터(가변 배열)로서 선언
    vector<vector<Edge>> graph;
    // 초기 크기를 설정하지 않으면 index로 참조할 때 에러 발생 가능
    // push_back으로서 크기를 뒤에서부터 하나씩 늘리거나 resize로 한번에 늘린다.
    graph.resize(vertexCnt + 1);

    // 그래프 입력받기
    for (int i = 0; i < edgeCnt; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;

        // 무방향 그래프이므로 a~b, b~a를 각각 넣어준다.
        graph[a].push_back({b, dist});
        graph[b].push_back({a, dist});
    }

    // 무조건 거쳐가야 하는 간선의 start와 end (혹은 end와 start)
    int v1, v2;
    cin >> v1 >> v2;

    /////// 입력 끝 ///////

    // 정답이 나오는 데는 두 가지 가능성이 있다.
      // 1. (start ~ V1) + (V1 ~ V2) + (V2 ~ End)
      // 2. (start ~ V2) + (V2 ~ V1) + (V1 ~ End)
    long long startToV1, v1ToV2, v2ToEnd;
    long long startToV2, v1ToEnd;

    vector<int> minDistArr;
    minDistArr.resize(vertexCnt + 1);

    // start(1)에서 시작해서 다른 모든 정점의 거리를 구한다.
    dijkstra(graph, 1, minDistArr);
    startToV1 = minDistArr[v1]; // start에서 V1까지의 거리와
    startToV2 = minDistArr[v2]; // start에서 V2까지의 거리를 구할 수 있다.

    // 마찬가지로 V1에서 시작
    dijkstra(graph, v1, minDistArr);
    v1ToV2 = minDistArr[v2]; // V1에서 V2까지의 거리와
    v1ToEnd = minDistArr[vertexCnt]; // V1에서 end까지의 거리를 구한다.

    // V2에서 시작
    dijkstra(graph, v2, minDistArr);
    v2ToEnd = minDistArr[vertexCnt]; // V2에서 end까지의 거리를 구한다.
    // V2에서 V1까지의 거리는 V1에서 V2까지의 거리와 같으므로 구할 필요는 없다.

    // 두 경우 중 더 짧은 거리를 구한다.
    long long ans = min((long long)0x3f3f3f3f, startToV1 + v1ToV2 + v2ToEnd);
    ans = min(ans, startToV2 + v1ToV2 + v1ToEnd);

    // 거리가 무한대라면 -1을, 그렇지 않다면 정답 출력
    cout << (ans == 0x3f3f3f3f ? -1 : ans);
}

// start로부터 모든 정점까지의 거리를 구하는 데이크스트라 알고리즘
// minDistArr는 const 아닌 참조(call by reference)이므로 함수 호출 시 minDistArr 자리에 넣은 벡터 요소의 값이 바뀔 수 있다.
void dijkstra(const vector<vector<Edge>>& graph, int start, OUT vector<int>& minDistArr)
{
    // 정점 총 개수를 graph 크기로부터 가져온다.
    int vertexCnt = graph.size() - 1;

    // cmp로 비교하는 우선순위 큐
    priority_queue<Edge, vector<Edge>, cmp> pq;

    // 없는 정점으로부터 시작 정점으로 이어준다. (그래야 while문 순회 가능)
    pq.push({start, 0});
    for (int i = 0; i <= vertexCnt; i++)
    {
        // minDistArr 초기화
        minDistArr[i] = 0x3f3f3f3f;
    }
    // start에서 start까지의 거리는 0이다.
    minDistArr[start] = 0;

    // 우선순위 큐에 빼낼 간선이 있을 경우
    while (pq.empty() == false)
    {
        Edge currEdge = pq.top(); pq.pop();

        // pq 맨 상위에 있는 간선의 정점(end)에 이어진 간선 살펴보기
        for (Edge nextEdge : graph[currEdge.end])
        {
            // (start에서부터 )nextEdge로 가는 원래 길보다
            // 더 짧은 지름길 발견 시(start ~ currEdge + currEdge ~ nextEdge)
            if (minDistArr[nextEdge.end] > minDistArr[currEdge.end] + nextEdge.dist)
            {
                // nextEdge로 가는 원래 길을 지름길로 교체한다
                minDistArr[nextEdge.end] = minDistArr[currEdge.end] + nextEdge.dist;

                // 새로 만들어진 지름길을 다른 간선들이 비교하지 못했을 가능성이 있으므로
                // push 해서 재검사한다.
                pq.push({nextEdge.end, minDistArr[nextEdge.end]});
            }
        }
    }
}
