#include <iostream>
using namespace std;

long long fibo[117] = {0};

long long f(int n) {
	if (fibo[n] != 0) {
		return fibo[n];
	} 
	if (n <= 3) {
		fibo[n] = 1;
		return 1;
	} else {
		fibo[n] = f(n-1) + f(n-3);
		return fibo[n];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	cout << f(n) << endl;
}

