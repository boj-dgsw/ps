#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[25];
bool isUsed[25];
int ans; 

void func(int depth, int summ) {
	if (depth == N) {
		if (summ == S) {
			ans++;
		}
		return;
	}

	func(depth + 1, summ + arr[depth]);
	func(depth + 1, summ);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	func(0, 0);

	if (S == 0) {
		ans--;
	}

	cout << ans;

	return 0;
} 