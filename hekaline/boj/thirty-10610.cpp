// 배수 판정법
// 30의 배수가 되려면 0이 최소 한 개 존재하면서 각 자리의 숫자의 합이 3의 배수여야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); \
				cin.tie(nullptr);\
				cout.tie(nullptr);

using namespace std;

int main()
{
	FAST_IO;
	
	string s;
	cin >> s;
	
	int sum = 0;
	bool bZeroExists = false;
	
	for (int i = 0; i < s.length(); i++)
	{
		sum += s[i] - '0';
		if (s[i] - '0' == 0)
			bZeroExists = true;
	}

  // 각 자리의 합이 3의 배수이면서 0이 한 개 존재해야 한다.
  // 그렇지 않으면 -1 출력
	if (sum % 3 != 0 || !bZeroExists)
	{
		cout << -1;
		return 0;
	}

  // 문자열 내림차순 정렬
	sort(s.begin(), s.end(), greater());
	cout << s;
}
