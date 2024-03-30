package 석유_시추;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public int solution(int[][] land) {
        int answer = 0;
        int n = land.length;
        int m = land[0].length;
        int[] sums = new int[m];

        boolean[][] visit = new boolean[n][m];
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(land[i][j] == 1 && !visit[i][j]) {
                    int cnt = 0;
                    int left = j;
                    int right = j;
                    Queue<Place> que = new LinkedList<>();
                    que.add(new Place(i, j));

                    while(!que.isEmpty()) {
                        Place place = que.poll();
                        int x = place.x;
                        int y = place.y;

                        if(!visit[x][y]) {
                            cnt++;
                            visit[x][y] = true;
                            left = Math.min(left, y);
                            right = Math.max(right, y);

                            if(x + 1 < n && land[x + 1][y] == 1) {
                                que.add(new Place(x + 1, y));
                            }
                            if(x - 1 > -1 && land[x - 1][y] == 1) {
                                que.add(new Place(x - 1, y));
                            }
                            if(y + 1 < m && land[x][y + 1] == 1) {
                                que.add(new Place(x, y + 1));
                            }
                            if(y - 1 > -1 && land[x][y - 1] == 1) {
                                que.add(new Place(x, y - 1));
                            }
                        }
                    }

                    for(int k = left; k<=right; k++) {
                        sums[k] += cnt;
                    }
                }
            }
        }

        for(int sum : sums) {
            answer = Math.max(answer, sum);
        }

        return answer;
    }

    static class Place {

        int x, y;

        Place(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
