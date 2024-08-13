#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> room(55, vector<int>(55, 0));
vector<vector<bool>> visited(55, vector<bool>(55, false));

struct Robot {
    int y, x, dir;
};

Robot robot;

int dy[4] = { -1, 0, 1, 0 }; 
int dx[4] = { 0, 1, 0, -1 }; 

void input() {
    cin >> N >> M;
    cin >> robot.y >> robot.x >> robot.dir;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }
}

void robot_cleaning() {
    int cleaned_count = 0;

    while (true) {
        if (!visited[robot.y][robot.x]) {
            visited[robot.y][robot.x] = true;
            cleaned_count++;
        }

        bool found_unvisited = false;
        for (int i = 0; i < 4; i++) {
            robot.dir = (robot.dir + 3) % 4;
            int ny = robot.y + dy[robot.dir];
            int nx = robot.x + dx[robot.dir];

            if (ny >= 0 && nx >= 0 && ny < N && nx < M && room[ny][nx] == 0 && !visited[ny][nx]) {
                robot.y = ny;
                robot.x = nx;
                found_unvisited = true;
                break;
            }
        }

        if (!found_unvisited) {
            int back_dir = (robot.dir + 2) % 4;
            int ny = robot.y + dy[back_dir];
            int nx = robot.x + dx[back_dir];

            if (ny >= 0 && nx >= 0 && ny < N && nx < M && room[ny][nx] == 0) {
                robot.y = ny;
                robot.x = nx;
            } else {
                break;
            }
        }
    }

    cout << cleaned_count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    robot_cleaning();

    return 0;
}
