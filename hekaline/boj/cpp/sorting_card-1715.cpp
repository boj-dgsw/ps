#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int cnt = 0;
	int sum = 0;
	while (!pq.empty())
	{
		if (cnt++ == n - 1) break;

		int val1 = pq.top(); pq.pop();
		int val2 = pq.top(); pq.pop();

		sum += val1 + val2;
		pq.push(val1 + val2);
	}

	cout << sum;
}
