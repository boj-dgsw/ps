#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int arr[1'000'001];

int main()
{
	FAST_IO;
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		int g, x;
		cin >> g >> x;
		
		arr[x] += g;
	}
	
	long long currIce = 0;
	long long ans = 0;
	
	// 곰이 왼쪽 끝 + k에 있을 때
	for (int i = 0; i <= min(k * 2, 1'000'000); i++)
	{
		currIce += arr[i];
	}
	ans = currIce;
	
	// i는 곰의 이동 범위 맨 오른쪽 인덱스
	for (int i = k * 2 + 1; i <= 1'000'000; i++)
	{
		currIce -= arr[i - (k * 2 + 1)];
		currIce += arr[i];
		
		ans = max(ans, currIce);
	}
	
	cout << ans;
}
