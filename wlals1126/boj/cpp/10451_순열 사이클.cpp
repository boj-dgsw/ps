#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> arr;
vector<bool> visited;

void dfs(int j) {
    if (!visited[arr[j]]) {
        visited[arr[j]] = true;
        dfs(arr[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        arr.resize(n + 1);
        visited.assign(n + 1, false);

        for (int j = 1; j <= n; j++) {
            cin >> arr[j];
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                cnt++;
                visited[j] = true;
                dfs(j);
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
