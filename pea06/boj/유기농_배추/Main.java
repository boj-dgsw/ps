package 유기농_배추;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int test = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < test; i++) {
            st = new StringTokenizer(br.readLine());

            int row = Integer.parseInt(st.nextToken());
            int column = Integer.parseInt(st.nextToken());

            int[][] map = new int[row][column];
            int[][] visited = new int[row][column];

            int k = Integer.parseInt(st.nextToken());
            for (int j = 0; j < k; j++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                map[x][y] = 1;
            }

            int count = 0;

            for (int x = 0; x < row; x++) {
                for (int y = 0; y < column; y++) {
                    if (map[x][y] == 1 && visited[x][y] == 0) {
                        bfs(x, y, map, row, column, visited);
                        count++;
                    }
                }
            }

            System.out.println(count);
        }
    }

    static void bfs(int startX, int startY, int[][] map, int row, int column, int[][] visited) {
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{startX, startY});
        visited[startX][startY] = 1;

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
                    queue.offer(new int[]{x,y});
                    visited[x][y] = 1;
                }
            }

        }
    }
}
