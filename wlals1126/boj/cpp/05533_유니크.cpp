#include <iostream>
#include <math.h>
using namespace std;
int main() {

	int n;
	cin >> n;
	int **Player = new int*[n];

	int Card[100] = { 0, };
	int tmp;
	for (int i = 0; i < n; i++)
	{
		
		*(Player + i) = new int[3];
		for (int j = 0; j < 3; j++)
		{
			tmp = pow(10, j * 3);
			cin >> Player[i][j];
			Card[Player[i][j] - 1] = tmp+ Card[Player[i][j] - 1];
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			tmp = pow(10, j * 3);
			if ((Card[Player[i][j] - 1] /tmp)%200-1 == 0)
				sum = sum + Player[i][j];
		}
		cout << sum << "\n";
		sum = 0;
	}

}