#include <iostream>

using namespace std;

// 최대공약수
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

int main()
{
	int ab, ac, bd;
	
	while (true)
	{
		cin >> ab >> ac >> bd;
    if (cin.eof()) break;

    // D에서 C로 갈 동안 기울기가 어떻게 되는지 구한 후 A와 C 사이의 거리만큼 곱한다.
    int num = ab * ac;
		int deno = bd - ac;
		
		int gcd = GCD(num, deno);

    // 약분한 수 출력
		cout << num / gcd << '/' << deno / gcd << '\n';
	}
}
