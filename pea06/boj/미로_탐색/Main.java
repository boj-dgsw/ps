package 미로_탐색;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int row = Integer.parseInt(st.nextToken());
        int column = Integer.parseInt(st.nextToken());

        int[][] map = new int[row][column];

        for (int i = 0; i < row; i++) {
            String line = br.readLine();
            for (int j = 0; j < column; j++) {
                map[i][j] = Integer.parseInt(line.split("")[j]);
            }
        }

        Queue<int[]> queue = new LinkedList<>();
        int[][] visited = new int[row][column];
        int[][] distance = new int[row][column];
        queue.offer(new int[]{0,0});
        visited[0][0] = 1;
        distance[0][0] = 1;

        while (!queue.isEmpty()) {
            int[] poll = queue.poll();

            int[] dx = {-1, 1, 0,0};
            int[] dy = {0, 0, -1, 1};

            for (int i = 0; i < 4; i ++) {
                int x = poll[0] + dx[i];
                int y = poll[1] + dy[i];

                if (x < 0 || x >= row || y < 0 || y >= column) {
                    continue;
                }

                if (map[x][y] == 1 && visited[x][y] == 0) {
                    queue.offer(new int[]{x, y});
                    visited[x][y] = 1;
                    distance[x][y] = distance[poll[0]][poll[1]] + 1;

                    if (x == row - 1 && y == column - 1) {
                        System.out.println(distance[x][y]);
                        return;
                    }
                }
            }
        }
    }
}
