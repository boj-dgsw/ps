package 쩜프왕_쩰리_Large;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        map = new int[n][n];
        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        boolean[][] visit = new boolean[n][n];
        Queue<Tile> que = new LinkedList<>();
        que.add(new Tile(0, 0, map[0][0]));

        while(!que.isEmpty()) {
            Tile tile = que.poll();
            int x = tile.x;
            int y = tile.y;
            int jump = tile.jump;

            if(!visit[x][y]) {
                visit[x][y] = true;

                if(n - 1 == x && x == y) {
                    System.out.print("HaruHaru");
                    return ;
                }

                if(x + jump < n) {
                    que.add(new Tile(x + jump, y, map[x + jump][y]));
                }
                if(x - jump > -1) {
                    que.add(new Tile(x - jump, y, map[x - jump][y]));
                }
                if(y + jump < n) {
                    que.add(new Tile(x, y + jump, map[x][y + jump]));
                }
                if(y - jump > -1) {
                    que.add(new Tile(x, y - jump, map[x][y - jump]));
                }
            }
        }

        System.out.print("Hing");
    }

    static class Tile {

        int x, y, jump;

        Tile(int x, int y, int jump) {
            this.x = x;
            this.y = y;
            this.jump = jump;
        }

    }

}
