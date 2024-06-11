#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int k;
	cin >> k;
	
	map<int, int> chocolates;

  // k보다 크거나 같은 2의 배수인 초콜릿의 크기 구하기
	int i;
	for (i = 1; i < k; i *= 2);
	chocolates[i] = 1;
	
	int sum = i;
	int minSizeToBuy = i;
	
	int cutCnt = 0;
	while (true)
	{
		int diff = sum - k;
		if (diff == 0) break;
		
		int chosenSize;
		
		for (chosenSize = 2; ; chosenSize *= 2)
		{
			if (chosenSize >= diff && chocolates.count(chosenSize) != 0) break;
		}

    // 초콜릿을 반으로 가르고 그 중 한 조각을 더함
		chocolates[chosenSize] -= 1;
		chocolates[chosenSize / 2] += 1;

    // 빼야 하는 초콜릿 수가 반으로 자른 초콜릿의 크기보다 크거나 같다면 (반으로 자른 초콜릿을 뺄 수 있다면)
		if (diff >= chosenSize / 2)
		{
      // 반으로 자른 초콜릿의 한 조각 빼기
			sum -= chosenSize / 2;
		}
		else
		{
      // 다시 초코 배열에 집어넣기
			chocolates[chosenSize / 2] += 1;
		}
		// 몇 번 잘랐는지
		cutCnt += 1;
	}
	
	cout << minSizeToBuy << ' ' << cutCnt;
}
