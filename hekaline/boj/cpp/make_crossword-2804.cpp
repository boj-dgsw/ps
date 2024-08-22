// implementation
// string
// Bronze I

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	
	int aLen = a.length();
	int bLen = b.length();
	
	bool bBreak = false;
	int selI, selJ;
	for (selI = 0; selI < aLen; selI++)
	{
		for (selJ = 0; selJ < bLen; selJ++)
		{
			if (a[selI] == b[selJ])
			{
				bBreak = true;
				break;
			}
		}
		
		if (bBreak) break;
	}
	
	for (int i = 0; i < bLen; i++)
	{
		if (i == selJ)
		{
			cout << a << '\n';
		}
		else
		{
			for (int j = 0; j < selI; j++)
				cout << '.';
			
			cout << b[i];
			
			for (int j = selI + 1; j < aLen; j++)
			{
				cout << '.';
			}
			
			cout << '\n';
		}
	}
}
