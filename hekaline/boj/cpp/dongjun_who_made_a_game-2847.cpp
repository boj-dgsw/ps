// Greedy

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
