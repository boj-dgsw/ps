package 안전_영역;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] area = new int[n][n];

        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<n; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int max = 0;
        for(int height = 0; height<=100; height++) {
            int cnt = 0;
            boolean[][] visit = new boolean[n][n];
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    if(area[i][j] > height && !visit[i][j]) {
                        cnt++;
                        Queue<Place> que = new LinkedList<>();
                        que.add(new Place(i, j));
                        while(!que.isEmpty()) {
                            Place place = que.poll();
                            int x = place.x;
                            int y = place.y;
                            if(!visit[x][y]) {
                                visit[x][y] = true;
                                if(x + 1 < n && area[x + 1][y] > height) {
                                    que.add(new Place(x + 1, y));
                                }
                                if(x - 1 > -1 && area[x - 1][y] > height) {
                                    que.add(new Place(x - 1, y));
                                }
                                if(y + 1 < n && area[x][y + 1] > height) {
                                    que.add(new Place(x, y + 1));
                                }
                                if(y - 1 > -1 && area[x][y - 1] > height) {
                                    que.add(new Place(x, y - 1));
                                }
                            }
                        }
                    }
                }
            }
            max = Math.max(max, cnt);
        }
        System.out.print(max);
    }

    static class Place {

        int x, y;

        Place(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}