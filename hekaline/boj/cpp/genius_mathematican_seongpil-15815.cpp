// 후위 표기식으로 입력되는 값 계산

#include <iostream>
#include <bits/stdc++.h>
#define cti charToInt
#define itc intToChar

using namespace std;

bool isNumber(char c)
{ return '0' <= c && c <= '9'; }

int charToInt(char c)
{ return c - '0'; }

char intToChar(int n)
{ return n + '0'; }

int main()
{
	stack<int> s;
	int sum = 0;
	
	string str;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		
		if (isNumber(c))
		{
			// 숫자이면 스택에 넣기
			s.emplace(cti(c));
		} else
		{
			// 연산자
			int a = s.top(); s.pop();
			int b = s.top(); s.pop();
			
			switch (c)
			{
				case '+': s.emplace(a + b); break;
				case '-': s.emplace(b - a); break;
				case '*': s.emplace(a * b); break;
				case '/': s.emplace(b / a); break;
				default: break;
			}
		}
	}
	
	cout << s.top();
}
