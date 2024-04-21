// 중간에서 만나기 (MITM: Meet In The Middle)
// 이분 탐색 (binary_search)

#include <iostream>
#include <vector>
#include <map>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input();
void findLeft(int start, int sum);
void findRight(int mid, int sum);

int n, s;
vector<int> vec;
map<int, int> sumMap;
long long ans = 0;

int main()
{
	FAST_IO;
	
	input();
	findLeft(0, 0);
	findRight(n / 2 + 1, 0);
	
	// findLeft에서 sum의 기본값이 0으로 들어가므로 s가 0이라면 공집합이 나올 수 있다.
	cout << (s == 0 ? ans - 1 : ans);
}

void findLeft(int start, int sum)
{
	// 왼쪽 수열 탐색 종료
	if (start == n / 2 + 1)
	{
		// 공집합이 sumMap[0]에 영향을 줄 수도 있다.
		sumMap[sum] += 1;
		return;
	}
	
	// 이 줄 때문에 왼쪽 수열 탐색 종료 시 공집합이 나올 수 있음. (sum에 아무것도 더하지 않음)
	findLeft(start + 1, sum);
	
	findLeft(start + 1, sum + vec[start]);
}

void findRight(int mid, int sum)
{
	// 오른쪽 수열 탐색 종료
	if (mid == n)
	{
		// sum과 더했을 때 s가 되는 수의 개수를 ans에 더함
		ans += sumMap[s-sum];
		return;
	}
	
	findRight(mid + 1, sum);
	findRight(mid + 1, sum + vec[mid]);
}

void input()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
}
