// Greedy

// 배열 내 요소(점수)들을 1씩 빼서 오름차순으로 만들어야 함.
// 예로 들어 4를 빼면 4번으로 간주한다.
// 점수 빼는 횟수는 최소로 해야 함.

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); \
				cin.tie(nullptr);                 \
				cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	
	int n;
	cin >> n;
	
	vector<int> scores(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}
	
	int res = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		if (scores[i] >= scores[i + 1])
		{
			res += scores[i] - scores[i + 1] + 1;
			scores[i] = scores[i + 1] - 1;
		}
	}
	
	cout << res;
}
