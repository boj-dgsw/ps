#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int get_result(const int& n, const int& m);

int main()
{
	FAST_IO;
	
	int n, m;
	cin >> n >> m;
	
	cout << get_result(n, m);
}

int get_result(const int& n, const int& m)
{
	vector<vector<long long>> arr(n + 1, vector<long long>(m + 1));
	arr[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		arr[i][1] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		arr[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			arr[i][j] = (arr[i-1][j] + arr[i][j-1] + arr[i-1][j-1]) % 1'000'000'007;
		}
	}
	
	return arr[n][m];
}
