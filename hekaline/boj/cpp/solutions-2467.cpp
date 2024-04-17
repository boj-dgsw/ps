#include <iostream>
#include <vector>
#define OUT
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
void input(OUT int& n, OUT vector<int>& solutions);
pair<int, int> getTwoSolsCloseToZero(const vector<int>& solutions);

int main()
{
	FAST_IO
	int n;
	vector<int> solutions;
	
	input(n, solutions);
	
	pair<int, int> twoSols = getTwoSolsCloseToZero(solutions);
	cout << twoSols.first << ' ' << twoSols.second;
}

void input(OUT int& n, OUT vector<int>& solutions)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		solutions.push_back(tmp);
	}
}

pair<int, int> getTwoSolsCloseToZero(const vector<int>& solutions)
{
	int solSize = solutions.size();
	int front = 0;
	int back = solSize - 1;
	
	int minDist = 0x7f'fff'fff;
	pair<int, int> closestSols;
	
	while (front < back)
	{
		int currSol = solutions[front] + solutions[back];
		if (minDist > abs(currSol))
		{
			minDist = abs(currSol);
			closestSols = {solutions[front], solutions[back]};
		}
		
		if (currSol == 0) return closestSols;
		
		currSol < 0 ? front++ : back--;
	}
	
	return closestSols;
}
