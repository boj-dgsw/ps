#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;

int dfs(int r, int c) {
    if (dp[r][c])
        return dp[r][c];
    int maxCnt = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = r + dx[i];
        int ny = c + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (arr[nx][ny] > arr[r][c])
                maxCnt = max(dfs(nx, ny), maxCnt);
        }
    }

    return dp[r][c] = maxCnt + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = dfs(i, j);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
