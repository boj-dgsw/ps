// Greedy
// 개수가 홀수인 알파벳이 두 개 이상 존재하면 안 된다
// 나머지가 짝수라면 문자열의 반만 만든 뒤 뒤집은 문자열을 더하면 된다
// 개수가 홀수인 알파벳이 있다면 정답 가운데에 넣어야 한다.

#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

string getRes(string& s);

int main()
{
	FAST_IO;
	
	string s;
	cin >> s;
	cout << getRes(s);
}

string getRes(string& s)
{
	string res = "";
	vector<int> alphabetCnt('Z' - 'A' + 1);
	
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		alphabetCnt[s[i] - 'A'] += 1;
	}
	
	int size = alphabetCnt.size();
	bool foundOdd = false;
	char oddChar = '\0';
	
	for (int i = 0; i < size; i++)
	{
		// 알파벳 개수가 홀수라면
		if (alphabetCnt[i] % 2 == 1)
		{
			// 이미 홀수인 알파벳이 하나 이상 더 있다면
			if (foundOdd)
			{
				// 팰린드롬을 만들 수 없음
				return "I'm Sorry Hansoo";
			}
			
			// 그렇지 않다면 가능성은 있다.
			foundOdd = true;
			oddChar = 'A' + i;
		}
		
		// 알파벳 개수가 홀수인지 짝수인지든 간에 res에 반만큼 붙여준다.
		// AAABB -> res = "AB", resTemp = "BA", oddChar = 'A' -> res + resTemp = "ABBA" -> res + oddChar + resTemp = "ABABA"
		res += string(alphabetCnt[i] / 2, 'A' + i);
	}
	
	string resTemp = res;
	reverse(resTemp.begin(), resTemp.end());
	
	if (foundOdd)
	{
		return res + oddChar + resTemp;
	}
	return res + resTemp;
}
