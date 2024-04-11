#include <iostream>
#include <algorithm>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
using PII = pair<int, int>;


struct cmp
{
	bool operator()(PII& a, PII& b)
	{
		return a.first < b.first;
	}
};

int main()
{
	FAST_IO
	
	int n;
	cin >> n;

  vector<PII> arr;
  vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		
		arr.push_back({tmp, i});
	}
	
	sort(arr.begin(), arr.end(), cmp());
	ans.resize(n);
	
	for (int i(0); i < n; i++)
	{
		// cout << arr[i].second << ' ';
		ans[arr[i].second] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
}
