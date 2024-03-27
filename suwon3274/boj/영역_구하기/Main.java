package 영역_구하기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] map = new int[m + 1][n + 1];

        while(k-->0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st2.nextToken());
            int y1 = Integer.parseInt(st2.nextToken());
            int x2 = Integer.parseInt(st2.nextToken());
            int y2 = Integer.parseInt(st2.nextToken());

            for(int i = y1 + 1; i<=y2; i++) {
                for(int j = x1 + 1; j<=x2; j++) {
                    map[i][j] = 1;
                }
            }
        }

        List<Integer> counts = new ArrayList<>();
        boolean[][] visit = new boolean[m + 1][n + 1];
        for(int i = 1; i<=m; i++) {
            for(int j = 1; j<=n; j++) {
                if(map[i][j] == 0 && !visit[i][j]) {
                    int cnt = 0;
                    Queue<Place> que = new LinkedList<>();
                    que.add(new Place(i, j));

                    while(!que.isEmpty()) {
                        Place place = que.poll();
                        int x = place.x;
                        int y = place.y;

                        if(!visit[x][y]) {
                            visit[x][y] = true;
                            cnt++;

                            if(x + 1 <= m && map[x + 1][y] == 0) {
                                que.add(new Place(x + 1, y));
                            }
                            if(x - 1 > 0 && map[x - 1][y] == 0) {
                                que.add(new Place(x - 1, y));
                            }
                            if(y + 1 <= n && map[x][y + 1] == 0) {
                                que.add(new Place(x, y + 1));
                            }
                            if(y - 1 > 0 && map[x][y - 1] == 0) {
                                que.add(new Place(x, y - 1));
                            }
                        }
                    }

                    counts.add(cnt);
                }
            }
        }

        Collections.sort(counts);
        System.out.println(counts.size());
        for(int count : counts) {
            System.out.print(count + " ");
        }
    }

    static class Place {

        int x, y;

        Place(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}