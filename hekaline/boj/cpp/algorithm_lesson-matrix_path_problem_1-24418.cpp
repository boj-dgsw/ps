// Dynamic Programming
// Memoization

// 행렬 경로를 구할 때 재귀로 몇 번 방문하는지 구한다.
// 근데 이것도 DP로 구할 수 있다.

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using std::ios_base;
using std::cin;
using std::cout;
using std::vector;

void input();
int getRecurseCnt();

int n;
vector<vector<int>> arr;

int main()
{
	FAST_IO;
	
	input();
	
	cout << getRecurseCnt() + 1 << ' ' << n * n;
}

void input()
{
	cin >> n;
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(n);

    // 사실 arr 원소를 받을 필요는 없다.
	//for (int j = 0; j < n; j++)
	//{
			// cin >> arr[i][j];
	//}
	}
}

bool isIndexValid(int currI, int currJ)
{ return currI >= 0 && currJ >= 0 && currI < n && currJ < n; }

// 재귀 횟수를 구하는데, 이것도 DP이다.
int getRecurseCnt()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 1;
		}
	}
	
	// 현재 위치에서 오른쪽이나 아래를 방문할 수 있으면
  // 그곳에 현재 위치의 값을 더한다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isIndexValid(i, j + 1))
				arr[i][j + 1] += arr[i][j];
		}
		
		for (int j = 0; j < n; j++)
		{
			if (isIndexValid(i + 1, j))
				arr[i + 1][j] += arr[i][j];
		}
	}
	
	return arr[n - 1][n - 1];
}
