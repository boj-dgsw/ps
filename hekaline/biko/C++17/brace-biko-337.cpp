#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

stack<char> st;

int main()
{
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int ans = 0;
	
	for (int i = 0; i < n * 2; i++)
	{
		char c = s[i];
		if (c == '(')
		{
			st.push('(');
		} else // if (c == ')')
		{
			if (st.top() == '(')
			{
				ans += 1;
				st.pop();
			} else
			{
				st.push(')');
			}
		}
	}
	
	cout << ans + st.size();
}
