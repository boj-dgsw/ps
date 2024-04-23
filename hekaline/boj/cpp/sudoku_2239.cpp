// 백트래킹
// 구현

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input();
void backTracking(int idx);
bool canVisit(int currI, int currJ, int n);

vector<vector<short>> vec;
vector<pair<short, short>> emptyArr;

bool isIndexValid(int currI, int currJ)
{
	return currI >= 0 && currJ >= 0 && currI < 9 && currJ < 9;
}

int main()
{
	FAST_IO;
	
	input();
	backTracking(0);
}

// emptyArr에 있는 좌표를 전부 채울 때까지 backtracking
void backTracking(int idx)
{
	if (idx == emptyArr.size())
	{
    // 빈 좌표를 다 채웠으면 전체 스도쿠 출력
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << vec[i][j];
			} cout << '\n';
		}

    // 해답이 여러 개 나올 수도 있어 출력 초과가 나올 수도 있다.
    // 사전 순으로 앞서는 것 하나만 출력하면 되므로 스도쿠 한 개 출력 후 종료한다.
		exit(0);
	}
	
	pair<int, int> currCoord = emptyArr[idx];
	int currI = currCoord.first;
	int currJ = currCoord.second;
	
	for (int n = 1; n <= 9; n++)
	{
    // 일부가 비어 있는 스도쿠에서 좌표가 currI, currJ인 곳을 n으로 채울 수 있는가?
		if (canVisit(currI, currJ, n))
		{
			vec[currI][currJ] = (short)n;
			
			backTracking(idx + 1);

      // 백트래킹하고 돌아왔다면(스도쿠의 currI, currJ 좌표에 n을 채웠는데 답이 나오지 않는다면)
      // 다시 비워주고 다른 수를 넣어본다.
			vec[currI][currJ] = 0;
		}
	}
}

// 가로줄, 세로줄, 자기가 속한 9칸의 큰 정사각형 탐색
// n과 같은 수가 나오면 false, 그렇지 않으면(arr[i][j]에 들어갈 수 있다면) true를 반환한다.
bool canVisit(int currI, int currJ, int n)
{
	if (!isIndexValid(currI, currJ)) return false;
	
	int h = currI / 3;
	int w = currJ / 3;
	
	// 네모 안
	for (int i = h * 3; i < h * 3 + 3; i++)
	{
		for (int j = w * 3; j < w * 3 + 3; j++)
		{
			if (currI == i && currJ == j) continue;
			
			if (vec[i][j] == n)
			{
				return false;
			}
		}
	}
	
	// 가로 탐색
	for (int j = 0; j < 9; j++)
	{
		if (currJ == j) continue;
		
		if (vec[currI][j] == n)
		{
			return false;
		}
	}
	
	// 세로 탐색
	for (int i = 0; i < 9; i++)
	{
		if (currI == i) continue;
		
		if (vec[i][currJ] == n)
		{
			return false;
		}
	}
	
	return true;
}


void input()
{
	vec.resize(9);
	for (int i = 0; i < 9; i++)
	{
		vec[i].resize(9);
		for (int j = 0; j < 9; j++)
		{
			char temp;
			cin >> temp;
			vec[i][j] = temp - '0';
			
			if (vec[i][j] == 0)
			{
				emptyArr.emplace_back(i, j);
			}
		}
	}
}

