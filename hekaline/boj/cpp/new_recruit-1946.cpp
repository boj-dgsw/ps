#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.first < b.first;
	}
};

int main()
{
	FAST_IO;
	int t;
	cin >> t;
	vector<pair<int, int>> arr;
	
	while (t--)
	{
		int n;
		cin >> n;
		
		arr.resize(n);
		for (auto& e : arr)
			cin >> e.first >> e.second; // input element
			
		int minVal = 2'147'483'647;
		int ans = 0;
		sort(arr.begin(), arr.end(), cmp());
		
		for (auto& e : arr)
		{
			if (e.second <= minVal)
			{
				minVal = e.second;
				ans += 1;
			}
		}
		
		cout << ans << '\n';
	}
}
