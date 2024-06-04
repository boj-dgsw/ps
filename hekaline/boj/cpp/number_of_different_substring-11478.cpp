// hash/tree (해시를 사용한 집합과 맵)
// string(문자열)

#include <iostream>
#include <map>

using namespace std;

map<string, bool> checked;

int main()
{
	string s;
	cin >> s;
	
	int len = s.length();
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j <= len - i; j++)
		{
			checked[s.substr(j, i)] = true;
		}
	}
	
	cout << checked.size();
}
