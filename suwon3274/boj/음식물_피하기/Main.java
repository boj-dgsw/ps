package 음식물_피하기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        char[][] map = new char[n + 1][m + 1];

        while(k-->0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st2.nextToken());
            int c = Integer.parseInt(st2.nextToken());
            map[r][c] = '*';
        }

        int result = 0;
        boolean[][] visit = new boolean[n + 1][m + 1];
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(map[i][j] == '*' && !visit[i][j]) {
                    int cnt = 0;
                    Queue<Trash> que = new LinkedList<>();
                    que.add(new Trash(i, j));

                    while(!que.isEmpty()) {
                        Trash trash = que.poll();
                        int x = trash.x;
                        int y = trash.y;

                        if(!visit[x][y]) {
                            cnt++;
                            visit[x][y] = true;

                            if(x + 1 <= n && map[x + 1][y] == '*') {
                                que.add(new Trash(x + 1, y));
                            }
                            if(x - 1 > 0 && map[x - 1][y] == '*') {
                                que.add(new Trash(x - 1, y));
                            }
                            if(y + 1 <= m && map[x][y + 1] == '*') {
                                que.add(new Trash(x, y + 1));
                            }
                            if(y - 1 > 0 && map[x][y - 1] == '*') {
                                que.add(new Trash(x, y - 1));
                            }
                        }
                    }

                    result = Math.max(result, cnt);
                }
            }
        }
        System.out.print(result);
    }

    static class Trash {

        int x, y;

        Trash(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
