package 게임_맵_최단거리;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;

        Queue<Place> que = new LinkedList<>();
        que.add(new Place(0, 0, 0));

        boolean[][] visit = new boolean[n][m];
        while(!que.isEmpty()) {
            Place place = que.poll();
            int x = place.x;
            int y = place.y;
            int dis = place.dis;

            if(!visit[x][y]) {
                visit[x][y] = true;

                if(x == n - 1 && y == m - 1) {
                    return dis + 1;
                }

                if(x + 1 < n && maps[x + 1][y] == 1) {
                    que.add(new Place(x + 1, y, dis + 1));
                }
                if(x - 1 > -1 && maps[x - 1][y] == 1) {
                    que.add(new Place(x - 1, y, dis + 1));
                }
                if(y + 1 < m && maps[x][y + 1] == 1) {
                    que.add(new Place(x, y + 1, dis + 1));
                }
                if(y - 1 > -1 && maps[x][y - 1] == 1) {
                    que.add(new Place(x, y - 1, dis + 1));
                }
            }
        }

        return -1;
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
