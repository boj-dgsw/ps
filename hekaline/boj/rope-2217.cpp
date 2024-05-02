// Greedy (그리디)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<short> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

  // 오름차순 정렬
	sort(arr.begin(), arr.end());
	
	int maxWeight = -1;
	for (int i = 0; i < n; i++)
	{
    // arr[i]는 버틸 수 있는 하중이 i번째로 낮은 로프이다.
    // 정답 = max(현재까지 찾은 최대 무게, i번째로 하중이 가장 낮은 로프 하중 * (로프 개수 - arr[i]보다 더 약한 로프 개수))
		maxWeight = max(maxWeight, arr[i] * (n - i));
	}
	
	cout << maxWeight;
}
