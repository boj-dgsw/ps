// 태그 내 문자열 제외한 단어들을 모두 뒤집기
// String(문자열)
// Silver III

#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

void emptyStack(stack<char>& st)
{
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}

int main()
{
	FAST_IO;
	
	string s;
	getline(cin, s);
	stack<char> st;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '<')
		{
			emptyStack(st);
			while (true)
			{
				cout << s[i];
				if (s[i] == '>') break;
				i++;
			}
		}
		else if (s[i] == ' ')
		{
			emptyStack(st);
			cout << ' ';
		}
		else
			st.push(s[i]);
	}
	
	emptyStack(st);
}
