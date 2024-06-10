// greedy
// silver II

#include <iostream>
#include <vector>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main()
{
	// 빠른 입출력
	FAST_IO;
	// 오리 울음 순서
	char seq[5] = {'q', 'u', 'a', 'c', 'k'};
	// 오리 배열
	vector<char> ducks;
	
	// 녹음 기록 (입력받는 값)
	string record;
	cin >> record;
	
	for (const auto& c : record)
	{
		// c의 seq 내의 순서
		int i;
		// c가 오리 울음(seq) 순서의 몇 번째인가를 구함
		for (i = 0; i < sizeof(seq); i++)
		{
			if (seq[i] == c) break;
		}
		
		// 오리 울음이 유효한지 여부
		bool isValid = false;
		for (auto& duck : ducks)
		{
			if (i == 0)
			{
				// 오리 울음 재시작
				if (duck == seq[4])
				{
					duck = seq[i];
					isValid = true;
					break;
				}
			}
				
				// duck이 seq[i - 1]인 경우
				// (duck이 'c'였는데 seq[i]가 'k'인 경우, duck이 'q'였는데 seq[i]가 'u'인 경우 등)
			else if (duck == seq[i - 1])
			{
				duck = seq[i];
				isValid = true;
				break;
			}
		}
		
		if (!isValid)
		{
			// c가 'q'이다
			if (i == 0)
			{
				// 새로운 오리의 울음
				ducks.push_back(seq[i]);
				isValid = true;
			}
			else
			{
				// 오리 소리가 유효하지 않음
				cout << -1;
				return 0;
			}
		}
	}
	
	for (const auto& duck : ducks)
	{
		// duck is not 'k'
		if (duck != seq[sizeof(seq) - 1])
		{
			// 오리 소리가 끝나지 않음 (= 유효하지 않음)
			cout << -1;
			return 0;
		}
	}
	
	// 오리 배열 개수
	cout << ducks.size();
}
