#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define PII pair<int, int>

using namespace std;

struct cmp
{
    // first: 도착 노드, second: 거리
    bool operator()(const PII& a, const PII& b)
    {
        return a.second > b.second;
    }
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{    
    // 최소 거리, shortest[0] = S, [1] = A, [2] = B
    vector<vector<int>> shortest(3, vector<int>(n + 1, 20'000'001));
    vector<vector<PII>> edges(n + 1);
    
    // S, A, B에서 자기 자신까지의 거리는 0이다.
    shortest[0][s] = 0;
    shortest[1][a] = 0;
    shortest[2][b] = 0;
    
    // edges 초기화
    for (int i = 0; i < fares.size(); i++)
    {
        const auto& fSet = fares[i];
        
        // 시작 지점 -> 도착 지점 거리
        edges[fSet[0]].emplace_back(fSet[1], fSet[2]);
        
        // 도착 지점 -> 시작 지점 거리
        edges[fSet[1]].emplace_back(fSet[0], fSet[2]);
    }
    
    // S 지점부터 데이크스트라, 그 다음 A와 B
    for (int i = 0; i <= 2; i++)
    {
        int selected = (i == 0 ? s : i == 1 ? a : b);
        
        // first: 도착 노드, second: 거리
        // 거리가 짧은 노드부터 살펴봐야 함
        priority_queue<PII, vector<PII>, cmp> pq;
        
        // S/A/B
        pq.emplace(selected, 0);
        
        while (!pq.empty())
        {
            // 현재 간선
            auto currEdge = pq.top(); pq.pop();
            
            // 간선의 도착지
            auto currEnd = currEdge.first;
            // 간선의 거리
            auto currDist = currEdge.second;
            
            // 간선 거리가 이미 찾은 가장 짧은 거리보다 멀다면
            if (currDist > shortest[i][currEnd])
                continue;
            
            // 그렇지 않다면 currEnd의 간선들 살펴보기
            for (auto& nextEdge : edges[currEnd])
            {
                // currEnd의 간선의 도착지
                auto nextEnd = nextEdge.first;
                // 그 간선의 거리
                auto nextDist = nextEdge.second;
                
                // 현재 찾은 currEnd까지의 가장 짧은 거리 + currEnd -> nextEnd로 가는 간선의 거리를
                // 이전까지 찾은 nextEnd로 가는 가장 짧은 거리와 비교
                if (shortest[i][nextEnd] > shortest[i][currEnd] + nextDist)
                {
                    // 더 짧은 길을 새로 찾는 데 성공
                    shortest[i][nextEnd] = shortest[i][currEnd] + nextDist;
                    
                    // 그 루트를 거쳐 다른 정점으로 가는 길 살펴보기
                    pq.emplace(nextEnd, shortest[i][nextEnd]);
                }
            }
        }
    }

    int ans = 2'147'483'647; // max distance
    
    // 동승해서 내리는 노드 i를 전부 돌면서 
    // (S -> 동승 하차) 거리 + (동승 하차 -> A) 거리 + (동승 하차 -> B) 거리 중 가장 짧은 거리 구하기
    for (int i = 1; i <= n; i++)
    {
        // S부터 동승 노드의 최소 거리
        int togetherDist = shortest[0][i];
        int togetherToADist = shortest[1][i];
        int togetherToBDist = shortest[2][i];
        
        ans = min(ans, togetherDist + togetherToADist + togetherToBDist);
    }
    
    return ans;
}
