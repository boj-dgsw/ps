// DP
// Memoization

#include <iostream>

using namespace std;

long long arr[1'000'010];
long long fibonacci(int n)
{
    arr[0] = 0;
	  arr[1] = arr[2] = 1;
        
    for (int i = 2; i <= n; i++)
    {
		    arr[i] = (arr[i - 1] + arr[i - 2]) % 1'000'007;
	  }
    
    return arr[n];
}

int main()
{
    int n;
    
    cin >> n;
    cout << fibonacci(n);
}
