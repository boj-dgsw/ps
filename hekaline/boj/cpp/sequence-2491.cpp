// 가장 긴 (같거나) 증가하는 수열의 길이 또는
// 가장 긴 (같거나) 감소하는 수열의 길이 구하기
// DP
// Implement

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n;
vector<int> arr;

void input();
int getLongestLen();

int main()
{
  // 빠른 입출력
	FAST_IO;
	input();
	
	cout << getLongestLen();
}

// 최댓값 (가장 긴 증가하는 부분 수열의 길이, 가장 긴 감소하는 부분 수열의 길이) 반환
int getLongestLen()
{
	int maxDecLen = 1;
	int maxIncLen = 1;
	int decLen = 1;
	int incLen = 1;
	
	for (int i = 1; i < n; i++)
	{
    // 오른쪽 수가 왼쪽 수보다 큰 경우(증가하는 경우)
		if (arr[i - 1] < arr[i])
		{
			maxDecLen = max(maxDecLen, decLen);
			decLen = 1;
			incLen += 1;
		}
    // 오른쪽 수가 왼쪽 수보다 작은 경우(감소하는 경우)
		else if (arr[i - 1] > arr[i])
		{
			decLen += 1;
			maxIncLen = max(maxIncLen, incLen);
			incLen = 1;
		}
    // 비교하는 수와 같은 경우
		else
		{
			decLen += 1;
			incLen += 1;
		}
	}

  // maxIncLen / maxDecLen이 구해지지 않는 경우도 있음.
	maxIncLen = max(maxIncLen, incLen);
	maxDecLen = max(maxDecLen, decLen);
	
	return max(maxIncLen, maxDecLen);
}

// 값 입력받기
void input()
{
	cin >> n;
	arr.resize(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
