package 그림;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] painting;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        painting = new boolean[n][m];
        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++) {
                painting[i][j] = "1".equals(st2.nextToken());
            }
        }

        int cntOfPainting = 0;
        int maxArea = 0;

        //boolean[][] visit = new boolean[n][m];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(painting[i][j]) {
                    cntOfPainting++;
                    int cnt = 0;

                    Queue<Area> que = new LinkedList<>();
                    que.add(new Area(i, j));

                    while(!que.isEmpty()) {
                        Area area = que.poll();
                        int x = area.x;
                        int y = area.y;

                        if(painting[x][y]) {
                            painting[x][y] = false;
                            cnt++;

                            if(x + 1 < n && painting[x + 1][y]) {
                                que.add(new Area(x + 1, y));
                            }
                            if(x - 1 > -1 && painting[x - 1][y]) {
                                que.add(new Area(x - 1, y));
                            }
                            if(y + 1 < m && painting[x][y + 1]) {
                                que.add(new Area(x, y + 1));
                            }
                            if(y - 1 > -1 && painting[x][y - 1]) {
                                que.add(new Area(x, y - 1));
                            }
                        }
                    }

                    maxArea = Math.max(maxArea, cnt);
                }
            }
        }

        System.out.println(cntOfPainting);
        System.out.print(maxArea);
    }

    static class Area {

        int x, y;

        Area(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
