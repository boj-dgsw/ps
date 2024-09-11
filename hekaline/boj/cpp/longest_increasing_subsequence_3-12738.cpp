// LIS: o(n log n)
// binary search
// Gold II

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1'000'000];
int lisLen[1'000'000];
int maxStreak[1'000'000];


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int len = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		int* pos = lower_bound(lisLen, lisLen + len, arr[i]);
		*pos = arr[i];
		maxStreak[i] = distance(lisLen, pos);

		if (pos == lisLen + len)
		{
			len += 1;
		}
	}
	
	cout << len << '\n';
}
