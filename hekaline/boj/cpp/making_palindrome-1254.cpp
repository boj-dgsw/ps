// Bruteforcing
// String
// Silver II

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(const string& s);

int main()
{
	string s;
	cin >> s;
	
	for (int i = 0; i < s.length() - 1; i++)
	{
		string subS = s.substr(i);
		// cout << subS << ' ' << endl;
		
		if (isPalindrome(subS))
		{
			cout << s.length() + i;
			return 0;
		}
	}
	
	cout << s.length() * 2 - 1;
}

bool isPalindrome(const string& s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}
	return true;
}
