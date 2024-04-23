// 정렬 + 이분 탐색
// 두 포인터
// 더했을 때 중성(0)에 가까워지는 세 용액을 구하는 문제

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void input();

vector<int> sols;
vector<int> ans(3, 0);
long long smallest = 1e18;

int n;
int main()
{
	FAST_IO;
	
	input();

  // 두 용액에 더할 한 가지 용액 index (총 3개가 된다.)
	for (int i = 0; i < n; i++)
	{
		int left = i + 1;
		int right = n - 1;

    // index 중복 방지
		if (left == i) left++;
		if (right == i) right--;

    // 두 용액 검색
		while (left < right)
		{
			long long sum = sols[i] + sols[left] + sols[right];

      // 용액이 중성에 가장 가깝다면
			if (abs(sum) < smallest)
			{
        // 중성(0)에서 얼마나 차이 나는지 새로 쓰기
				smallest = abs(sum);

        // 세 용액 기록
				ans[0] = sols[i];
				ans[1] = sols[left];
				ans[2] = sols[right];

        // 0(중성)이면 바로 중단해도 됨(스페셜 저지)
				if (smallest == 0)
				{
					sort(ans.begin(), ans.end());
					cout << sols[i] << ' ' << sols[left] << ' ' << sols[right];
					return 0;
				}
			}

      // 핵심 (합이 0보다 작으면 왼쪽 포인터를 오른쪽으로)
			if (sum < 0)
			{
				left++;
				if (left == i) left++;
			} else if (sum > 0) // 합이 0보다 크면 오른쪽 포인터를 왼쪽으로
			{
				right--;
				if (right == i) right--;
			}
		}
	}

  // 오름차순 출력이므로 정렬
	sort(ans.begin(), ans.end());
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sols.emplace_back(temp);
	}
	
	// 이진 탐색을 할 때 정렬은 필수이다.
	sort(sols.begin(), sols.end());
}
