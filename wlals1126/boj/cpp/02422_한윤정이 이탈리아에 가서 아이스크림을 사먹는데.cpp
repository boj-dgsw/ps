#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, answer;
bool map[200][200];
bool visited[200];
int iceCream[3];

void dfs(int index, int depth);
bool isPossible();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    memset(map, false, sizeof(map));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        map[a][b] = true;
        map[b][a] = true;
    }

    answer = 0;
    dfs(0, 0);

    cout << answer << endl;

    return 0;
}

void dfs(int index, int depth) {
    if (depth == 3) {
        if (isPossible()) {
            answer++;
        }
        return;
    }

    for (int i = index; i < n; i++) {
        if (!visited[i]) {
            iceCream[depth] = i;
            visited[i] = true;
            dfs(i, depth + 1);
            visited[i] = false;
        }
    }
}

bool isPossible() {
    if (map[iceCream[0]][iceCream[1]] || map[iceCream[0]][iceCream[2]] || map[iceCream[1]][iceCream[2]]) {
        return false;
    } else {
        return true;
    }
}
