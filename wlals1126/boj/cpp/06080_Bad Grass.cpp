#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};  

int R, C; 
vector<vector<int>> grid;  
vector<vector<bool>> visited;  

void dfs(int x, int y) {
    visited[x][y] = true;  

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];  
        int ny = y + dy[i];  

        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && grid[nx][ny] > 0) {
            dfs(nx, ny); 
        }
    }
}

int main() {
    cin >> R >> C;
    grid.assign(R, vector<int>(C)); 
    visited.assign(R, vector<bool>(C, false));  

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j]; 
        }
    }

    int island_count = 0; 

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && grid[i][j] > 0) {
                island_count++; 
                dfs(i, j);  
            }
        }
    }

    cout << island_count << endl;

    return 0;
}
