#include <iostream>
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

void input();
int getPasswordNum();
int charToInt(char dna);

int sl, pl;
int req[4];
string s;

int main()
{
	FAST_IO;
	input();
	
	cout << getPasswordNum();
}

bool isMeetingReq(const int arr[])
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] < req[i]) return false;
	}
	return true;
}

int getPasswordNum()
{
	int res = 0;
	int arr[4] = {0, };
	
	for (int i = 0; i < pl; i++)
	{
		arr[charToInt(s[i])] += 1;
	}
	res += isMeetingReq(arr);
	
	for (int i = pl; i < sl; i++)
	{
		arr[charToInt(s[i - pl])] -= 1;
		arr[charToInt(s[i])] += 1;
		
		res += isMeetingReq(arr);
	}
	
	return res;
}

int charToInt(char dna)
{
	char dnas[] = { 'A', 'C', 'G', 'T'};
	for (int i = 0; i < 4; i++)
	{
		if (dnas[i] == dna)
			return i;
	}
	return -1;
}

void input()
{
	cin >> sl >> pl;
	cin >> s;
	
	for (auto& e : req)
		cin >> e;
}
