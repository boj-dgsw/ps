#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check_win(char base, char fr) { 
	if (base == 'S') {
		if (fr == 'S') return 1; 
		if (fr == 'P') return 2;
		if (fr == 'R') return 0;
	}
	if (base == 'P') {
		if (fr == 'S') return 0;
		if (fr == 'P') return 1;
		if (fr == 'R') return 2;
	}
	if (base == 'R') {
		if (fr == 'S') return 2;
		if (fr == 'P') return 0;
		if (fr == 'R') return 1;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
	int r,n;
	cin >> r;
    
	vector<char>sk(r);
	for (int i = 0; i < r; i++) cin >> sk[i];
	cin >> n;
	vector<vector<char>>friends(n,vector<char>(r)); //친구
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r; j++)
			cin >> friends[i][j];


	int score = 0, max_score = 0;
	for (int j = 0; j < r; j++) {
		int arr[3] = { 0,0,0 };
		for (int i = 0; i < n; i++) {
			arr[0] += check_win('S', friends[i][j]);
			arr[1] += check_win('P', friends[i][j]);
			arr[2] += check_win('R', friends[i][j]);

			score += check_win(sk[j], friends[i][j]);
		}
		max_score += max(arr[0], max(arr[1], arr[2]));
	}

	cout << score << '\n' << max_score << '\n';;
		
}