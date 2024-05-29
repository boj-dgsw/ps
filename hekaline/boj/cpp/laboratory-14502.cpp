#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr short EMPTY = 0;
constexpr short WALL = 1;
constexpr short VIRUS = 2;
constexpr int MAX_WALL_COUNT = 3;

class Laboratory
{
public:
	Laboratory(int _n, int _m)
	{
		build_facility(_n, _m);
	}
	
	// map의 크기를 할당한다.
	void build_facility(int _n, int _m)
	{
		this->n = _n;
		this->m = _m;
		
		map.resize(n);
		for (int i = 0; i < n; i++)
			map[i].resize(m);
	}
	
	void input()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
	}
	
	[[nodiscard]]
	int get_max_safe_area()
	{
		build_wall();
		
		return maxSafeArea;
	}
	
private:
	[[nodiscard]]
	bool valid_index(int i, int j) const
	{
		return i >= 0 && j >= 0 && i < n && j < m;
	}
	
	// map을 가지고 바이러스를 시뮬레이션한다.
	// 안전한 범위의 크기를 반환한다.
	// DFS 사용
	int simulate()
	{
		// 맵 (깊은) 복사
		auto map_copy = map;
		
		// 바이러스를 퍼뜨리기 위한 큐
		queue<pair<int, int>> q;
		
		// 초기 바이러스 탐색
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map_copy[i][j] != VIRUS)
					continue;
				
				// 만약 map[i][j]가 바이러스라면
				// 큐에 넣는다.
				q.emplace(i, j);
			}
		}
		
		// 바이러스가 아직 퍼질 수도 있음
		while (!q.empty())
		{
			// 바이러스가 퍼질 위치
			auto coord = q.front(); q.pop();
			
			// 상하좌우 오프셋
			vector<pair<int, int>> offsets = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
			
			// 오프셋 탐색
			for (auto offset : offsets)
			{
				// 오프셋을 더한 새 인덱스
				int new_i = coord.first + offset.first;
				int new_j = coord.second + offset.second;
				
				// 인덱스 미유효 또는 방문 체크
				if (!valid_index(new_i, new_j) || map_copy[new_i][new_j] != EMPTY)
					continue;
				
				// 유효한 인덱스 + 아직 방문하지 않음
				// 바이러스 퍼짐
				map_copy[new_i][new_j] = VIRUS;
				q.emplace(new_i, new_j);
			}
		}
		
		// 바이러스가 퍼진 후 안전한 공간의 개수 반환
		return count_safe_area(map_copy);
	}
	
	// map 내의 EMPTY 개수 반환
	[[nodiscard]]
	int count_safe_area(const vector<vector<short>>& _map) const
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (_map[i][j] == EMPTY)
					cnt += 1;
			}
		}
		
		return cnt;
	}
	
	// 초기 벽 짓기
	void build_wall() { build_wall(0); }
	
	// 벽 짓기, 백트래킹으로 모든 조합을 만들어낸다.
	void build_wall(int cnt)
	{
		if (cnt >= MAX_WALL_COUNT)
		{
			maxSafeArea = max(maxSafeArea, simulate());
			return;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != EMPTY) continue;
				
				// 만약 비어 있다면 벽을 세울 수 있음
				map[i][j] = WALL;
				build_wall(cnt + 1);
				map[i][j] = EMPTY;
			}
		}
	}
	
	// laboratory의 지도
	vector<vector<short>> map;
	
	// map 크기
	int n = 0, m = 0;
	
	// 안전한 곳 최대 크기
	int maxSafeArea = 0;
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	Laboratory lab(n, m);
	lab.input();
	
	cout << lab.get_max_safe_area();
}
