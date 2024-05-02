package 농장_관리;

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
        int[][] farm = new int[n][m];

        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++) {
                farm[i][j] = Integer.parseInt(st2.nextToken());
            }
        }

        int result = 0;
        boolean[][] top = new boolean[n][m];
        Set<Grid> topSet = new HashSet<>();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!top[i][j]) {
                    topSet.clear();
                    boolean isTop = true;

                    boolean[][] visit = new boolean[n][m];
                    Queue<Grid> que = new LinkedList<>();
                    que.add(new Grid(i, j));

                    while(!que.isEmpty()) {
                        Grid grid = que.poll();
                        int x = grid.x;
                        int y = grid.y;
                        int height = farm[x][y];

                        if(!visit[x][y]) {
                            visit[x][y] = true;
                            topSet.add(new Grid(x, y));
                            int[] xArr = {x - 1, x, x + 1};
                            int[] yArr = {y - 1, y, y + 1};

                            for(int k = 0; k<3; k++) {
                                for(int l = 0; l<3; l++) {
                                    if(xArr[k] == x && yArr[l] == y) {
                                        continue;
                                    }

                                    if(xArr[k] > -1 && xArr[k] < n && yArr[l] > -1 && yArr[l] < m) {
                                        int compare = farm[xArr[k]][yArr[l]];
                                        if(compare > height) {
                                            isTop = false;
                                            que.clear();
                                            break;
                                        } else if(compare == height) {
                                            que.add(new Grid(xArr[k], yArr[l]));
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if(isTop) {
                        result++;
                        for(Grid grid : topSet) {
                            top[grid.x][grid.y] = true;
                        }
                    }
                }
            }
        }
        System.out.print(result);
    }

    static class Grid {

        int x, y;

        Grid(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
