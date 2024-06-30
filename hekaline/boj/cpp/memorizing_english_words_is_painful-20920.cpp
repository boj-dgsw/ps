#include <iostream>
#include <bits/stdc++.h>
// 빠른 입출력
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

// 정렬 기준
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
  // 반복 횟수 많을 시 우선됨
	if (a.second != b.second)
		return a.second > b.second;

  // 단어가 길 시 우선됨
	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length();

  // abc 순으로 앞에 있을 시 우선됨
	for (int i = 0; i < a.first.length(); i++)
	{
		if (a.first[i] != b.first[i])
			return a.first[i] < b.first[i];
	}
	
	return false;
}

unordered_map<string, int> wordDict;

int main()
{
	FAST_IO;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;

    // m보다 짧은 단어는 외울 필요가 없다
		if (s.length() < m)
			continue;

		wordDict[s] += 1;
	}

  // MAP -> VECTOR
	vector<pair<string, int>> dictTemp;
	for (auto& word : wordDict)
	{
		dictTemp.emplace_back(word);
	}

  // 벡터로 변환 후 정렬 (map은 미지원)
	sort(dictTemp.begin(), dictTemp.end(), cmp);

  // 정렬된 순으로 출력
	for (const auto& word : dictTemp)
	{
		cout << word.first << '\n';
	}
}
