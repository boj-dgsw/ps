package 빙산;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] sea = new int[n][m];

        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++) {
                sea[i][j] = Integer.parseInt(st2.nextToken());
            }
        }

        int answer = 0;
        boolean[][] visit = new boolean[n][m];
        while(true) {
            Map<Iceberg, Integer> map = new HashMap<>();
            int cnt = 0;
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    if(sea[i][j] > 0 && !visit[i][j]) {
                        cnt++;
                        Queue<Iceberg> que = new LinkedList<>();
                        que.add(new Iceberg(i, j));

                        while(!que.isEmpty()) {
                            Iceberg iceberg = que.poll();
                            int x = iceberg.x;
                            int y = iceberg.y;

                            if(!visit[x][y]) {
                                visit[x][y] = true;
                                int neighbors = 4;

                                if(x + 1 < n && sea[x + 1][y] > 0) {
                                    neighbors--;
                                    que.add(new Iceberg(x + 1, y));
                                }
                                if(x - 1 > 0 && sea[x - 1][y] > 0) {
                                    neighbors--;
                                    que.add(new Iceberg(x - 1, y));
                                }
                                if(y + 1 < m && sea[x][y + 1] > 0) {
                                    neighbors--;
                                    que.add(new Iceberg(x, y + 1));
                                }
                                if(y - 1 > 0 && sea[x][y - 1] > 0) {
                                    neighbors--;
                                    que.add(new Iceberg(x, y - 1));
                                }

                                map.put(iceberg, neighbors);
                            }
                        }
                    }
                }
            }

            if(cnt > 1) {
                System.out.print(answer);
                return ;
            }

            if(map.isEmpty()) {
                System.out.print(0);
                return ;
            }

            for(Iceberg iceberg : map.keySet()) {
                int neighbors = map.get(iceberg);
                int x = iceberg.x;
                int y = iceberg.y;

                if(sea[x][y] <= neighbors) {
                    sea[x][y] = 0;
                } else {
                    visit[x][y] = false;
                    sea[x][y] -= neighbors;
                }
            }

            answer++;
        }
    }

    static class Iceberg {

        int x, y;

        Iceberg(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
