#include <iostream>
#include <vector>
#define OUT

using namespace std;

int findRoot(OUT vector<int>& parents, int index)
{
	if (parents[index] == index)
		return index;
	return parents[index] = findRoot(parents, parents[index]);
}

bool unionTree(OUT vector<int>& parents, int parent, int child)
{
	int rootOfParent = findRoot(parents, parent);
	int rootOfChild = findRoot(parents, child);
	
	if (rootOfParent != rootOfChild)
	{
		parents[rootOfChild] = rootOfParent;
		return true;
	}
	
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int pointCnt;
	int turnCnt;
	
	cin >> pointCnt >> turnCnt;
	
	vector<int> parents;
	parents.resize(pointCnt);
	for (int i = 0; i < pointCnt; i++)
		parents[i] = i;
	
	for (int i = 1; i <= turnCnt; i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (a > b)
			swap(a, b);
		
		if (!unionTree(parents, a, b))
		{
			cout << i;
			return 0;
		}
	}
	
	cout << 0;
}
