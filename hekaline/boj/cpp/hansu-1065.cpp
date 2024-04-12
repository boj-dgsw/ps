#include <iostream>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main()
{
	FAST_IO
	
	int n;
	cin >> n;
	
	int sum = 0;
	
	for (int i = 1; i <= n; i++)
	{
		string str = to_string(i);
		int strlen = str.length();
		
		if (strlen <= 2)
		{
			sum += 1;
			continue;
		}
		
		int dif = str[1] - str[0];
		
		bool flag = true;
		for (int j = 2; j < strlen; j++)
		{
			if (str[j] - str[j-1] != dif)
			{
				flag = false;
				break;
			}
		}
		
		sum += flag;
	}
	
	cout << sum;
}
