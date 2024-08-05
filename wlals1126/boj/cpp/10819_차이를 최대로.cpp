#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int n;
vector<int> arr;
vector<int> selected;
vector<bool> visited;
int answer = INT_MIN;

void dfs(int depth) {
    if (depth == n) {
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += abs(selected[i] - selected[i + 1]);
        }
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            selected[depth] = arr[i];
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    arr.resize(n);
    selected.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    dfs(0);

    cout << answer << endl;

    return 0;
}
ㅊ
