#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b)
    {
        return a.second < b.second;
    }
};

vector<vector<int>> groupNum;
vector<pair<pair<int, int>, int>> groupDist; // 다른 그룹 사이의 높이
vector<int> parent;
int groupCnt = 0;

bool isValid(int i, int j, const vector<vector<int>>& land)
{
    return i >= 0 && j >= 0 && i < land.size() && j < land[0].size();
}

void groupBFS(vector<vector<int>>& land, pair<int, int> startCoord, int height)
{
    // 그룹 개수 += 1
    groupCnt += 1;

    queue<pair<int, int>> q;
    q.emplace(startCoord);

    while (!q.empty())
    {
        // 현재 좌표, 현재 i, j
        auto currCoord = q.front(); q.pop();
        auto currI = currCoord.first;
        auto currJ = currCoord.second;

        if (groupNum[currI][currJ] != 0) continue;
        groupNum[currI][currJ] = groupCnt;

        // 상하좌우 오프셋
        vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const auto& offset : offsets)
        {
            // 상하좌우
            int newI = currCoord.first + offset.first;
            int newJ = currCoord.second + offset.second;

            // 유효하지 않은 인덱스
            if (!isValid(newI, newJ, land))
                continue;

            // 지나갈 수 있는 높이 초과
            if (abs(land[currI][currJ] - land[newI][newJ]) > height)
                continue;

            q.emplace(newI, newJ);
        }
    }
}

void grouping(vector<vector<int>>& land, int height)
{
    groupNum.resize(land.size());
    for (auto& e : groupNum)
    {
        e.resize(land[0].size());
    }

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            // 그룹 넘버를 이미 매김
            if (groupNum[i][j] != 0) continue;

            groupBFS(land, {i, j}, height);
        }
    }
}

void findGroupDist(vector<vector<int>>& land, int height)
{
    vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            for (const auto& offset : offsets)
            {
                int newI = i + offset.first;
                int newJ = j + offset.second;

                // 같은 그룹의 땅
                if (groupNum[i][j] == groupNum[newI][newJ]) continue;

                groupDist.push_back({{groupNum[i][j], groupNum[newI][newJ]},
                                     abs(land[i][j] - land[newI][newJ])});
            }
        }
    }
}

int findParent(int n)
{
    if (n == parent[n]) return n;
    return parent[n] = findParent(parent[n]);
}

void unionGroup(int a, int b)
{
    parent[findParent(b)] = findParent(a);
}

bool hasSameParent(int a, int b)
{
    return findParent(a) == findParent(b);
}

int kruskal(vector<vector<int>>& land)
{
    parent.resize(groupCnt + 1);
    sort(groupDist.begin(), groupDist.end(), cmp());
    int ans = 0;

    for (int i = 1; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    for (const auto& e : groupDist)
    {
        int p1 = e.first.first;
        int p2 = e.first.second;
        int dist = e.second;

        if (hasSameParent(p1, p2)) continue;

        ans += dist;
        unionGroup(p1, p2);
    }

    return ans;
}

// land: 땅, height: 비용을 들이지 않고 올라갈 수 있는 최대 높이
int solution(vector<vector<int>> land, int height) {
    // groupNum의 [0~size][0~size]에 그룹 넘버를 매김
    grouping(land, height);
    findGroupDist(land, height);
    return kruskal(land);
}
