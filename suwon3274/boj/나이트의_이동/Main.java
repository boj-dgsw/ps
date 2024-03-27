package 나이트의_이동;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int startX = Integer.parseInt(st.nextToken());
            int startY = Integer.parseInt(st.nextToken());
            int endX = Integer.parseInt(st2.nextToken());
            int endY = Integer.parseInt(st2.nextToken());

            boolean[][] visit = new boolean[n][n];
            Queue<Place> que = new LinkedList<>();
            que.add(new Place(startX, startY, 0));

            while(!que.isEmpty()) {
                Place place = que.poll();
                int x = place.x;
                int y = place.y;
                int dis = place.dis;

                if(!visit[x][y]) {
                    visit[x][y] = true;

                    if(endX == x && endY == y) {
                        sb.append(dis).append("\n");
                        break;
                    }

                    if(x + 2 < n && y + 1 < n) {
                        que.add(new Place(x + 2, y + 1, dis + 1));
                    }
                    if(x + 1 < n && y + 2 < n) {
                        que.add(new Place(x + 1, y + 2, dis + 1));
                    }
                    if(x - 2 > -1 && y + 1 < n) {
                        que.add(new Place(x - 2, y + 1, dis + 1));
                    }
                    if(x - 1 > -1 && y + 2 < n) {
                        que.add(new Place(x - 1, y + 2, dis + 1));
                    }
                    if(x + 2 < n && y - 1 > -1) {
                        que.add(new Place(x + 2, y - 1, dis + 1));
                    }
                    if(x + 1 < n && y - 2 > -1) {
                        que.add(new Place(x + 1, y - 2, dis + 1));
                    }
                    if(x - 2 > -1 && y - 1 > -1) {
                        que.add(new Place(x - 2, y - 1, dis + 1));
                    }
                    if(x - 1 > -1 && y - 2 > -1) {
                        que.add(new Place(x - 1, y - 2, dis + 1));
                    }
                }
            }
        }
        System.out.print(sb);
    }

    static class Place {

        int x, y, dis;

        Place(int x, int y, int dis) {
            this.x = x;
            this.y = y;
            this.dis = dis;
        }

    }

}