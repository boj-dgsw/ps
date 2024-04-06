#include <iostream>
#include <cstdio>

using namespace std;
const int MAX = 21;
int num[MAX];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		getchar();
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - 1; j++) {
			num[j] = num[j + 1] - num[j];
		}
		n--;
	}
	for (int i = 0; i < n - 1; i++)
		cout << num[i] << ",";
	cout << num[n - 1] << endl;
	return 0;
}
