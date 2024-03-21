package 아이템_줍기;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    static int[][] map;

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        map = new int[51][51];
        for (int[] ints : rectangle) {
            for (int x = ints[0]; x <= ints[2]; x++) {
                for (int y = ints[1]; y <= ints[3]; y++) {
                    map[x][y] = 1;
                }
            }
        }

        Queue<Place> que = new LinkedList<>();
        que.add(new Place(characterX, characterY, 0));

        boolean[][] visit = new boolean[51][51];
        while(!que.isEmpty()) {
            Place place = que.poll();
            int x = place.x;
            int y = place.y;
            int dis = place.dis;

            if(!visit[x][y]) {
                visit[x][y] = true;
                if(itemX == x && itemY == y) {
                    return dis;
                }

                if(x + 1 < 51 && map[x + 1][y] == 1 && isEdge(51, x + 1, y)) {
                    que.add(new Place(x + 1, y, dis + 1));
                }
                if(x - 1 > -1 && map[x - 1][y] == 1 && isEdge(51, x - 1, y)) {
                    que.add(new Place(x - 1, y, dis + 1));
                }
                if(y + 1 < 51 && map[x][y + 1] == 1 && isEdge(51, x, y + 1)) {
                    que.add(new Place(x, y + 1, dis + 1));
                }
                if(y - 1 > -1 && map[x][y - 1] == 1 && isEdge(51, x, y - 1)) {
                    que.add(new Place(x, y - 1, dis + 1));
                }
            }
        }

        for(int i = 0; i<11; i++) {
            for(int j = 0; j<11; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println();

        for(int i = 0; i<11; i++) {
            for(int j = 0; j<11; j++) {
                System.out.print((map[i][j] == 1 && isEdge(11, i, j) ? 1 : 0) + " ");
            }
            System.out.println();
        }

        return -100;
    }

    static boolean isEdge(int n, int x, int y) {
        boolean isEdge = false;

        if(x + 1 < n && map[x + 1][y] == 0) {
            isEdge = true;
        } else if(x - 1 > -1 && map[x - 1][y] == 0) {
            isEdge = true;
        } else if(y + 1 < n && map[x][y + 1] == 0) {
            isEdge = true;
        } else if(y - 1 > -1 && map[x][y - 1] == 0) {
            isEdge = true;
        } else if(x - 1 > -1 && y - 1 > -1 && map[x - 1][y - 1] == 0) {
            isEdge = true;
        } else if(x + 1 < n && y + 1 < n && map[x + 1][y + 1] == 0) {
            isEdge = true;
        } else if(x + 1 < n && y - 1 > -1 && map[x + 1][y - 1] == 0) {
            isEdge = true;
        } else if(x - 1 > -1 && y + 1 < n && map[x - 1][y + 1] == 0) {
            isEdge = true;
        }

        return isEdge;
    }

    static class Place {

        int x, y, dis;

        Place(int x, int y, int dis) {
            this.x = x;
            this.y = y;
            this.dis = dis;
        }

    }

    public static void main(String[] args) {

        Solution solution = new Solution();

        int[][] rectangles = {{2, 2, 5, 5}, {1, 3, 6, 4}, {3, 1, 4, 6}};

        System.out.println(solution.solution(rectangles, 1, 4, 6, 3));

    }

}