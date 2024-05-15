// Greedy
// arr 요소들(위치)에 테이프를 모두 붙여야 하는데 테이프 길이는 l이다.
// 테이프 길이가 충분하다면 여러 위치에 테이프를 한 번에 붙일 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n, l;
vector<int> arr;

void input();
int get_result();

int main()
{
	FAST_IO;
	
	input();
	
	cout << get_result();
}

int get_result()
{
	int res = 0;
	int startN = arr[0];
	int next;
	
	for (int i = 0; i < n; i++)
	{
    // 테이프 시작한 위치에서부터 이번 위치까지의 길이
		next = arr[i] - startN + 1;

    // 테이프 길이보다 next가 길다면
		if (next > l)
		{
      // 테이프 붙이는 작업을 arr[i]에서부터 새로 시작한다.
			startN = arr[i];
			res += 1;
		}
	}
  // 테이프를 붙이고 있던 중이라면
	if (next != 0)
		res += 1;
	
	return res;
}

void input()
{
	cin >> n >> l;
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
}
