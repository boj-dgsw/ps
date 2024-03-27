package 탈출;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static char[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int startX = 0, startY = 0;
        map = new char[r][c];

        for(int i = 0; i<r; i++) {
            String s = br.readLine();
            for(int j = 0; j<c; j++) {
                map[i][j] = s.charAt(j);
                if(map[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }

        boolean[][] visit = new boolean[r][c];
        Queue<Place> que = new LinkedList<>();
        que.add(new Place(startX, startY, 0));

        int minute = 0;
        while(!que.isEmpty()) {
            Place place = que.poll();
            int x = place.x;
            int y = place.y;
            int dis = place.dis;

            if(minute != dis) {
                List<Place> water = new ArrayList<>();
                for(int i = 0; i<r; i++) {
                    for(int j = 0; j<c; j++) {
                        if(map[i][j] == '*') {
                            water.add(new Place(i, j, 0));
                        }
                    }
                }

                for(Place p : water) {
                    int i = p.x;
                    int j = p.y;
                    if(i + 1 < r && map[i + 1][j] != 'X' && map[i + 1][j] != 'D') {
                        map[i + 1][j] = '*';
                    }
                    if(i - 1 > -1 && map[i - 1][j] != 'X' && map[i - 1][j] != 'D') {
                        map[i - 1][j] = '*';
                    }
                    if(j + 1 < c && map[i][j + 1] != 'X' && map[i][j + 1] != 'D') {
                        map[i][j + 1] = '*';
                    }
                    if(j - 1 > -1 && map[i][j - 1] != 'X' && map[i][j - 1] != 'D') {
                        map[i][j - 1] = '*';
                    }
                }
                minute++;
            }

            if(!visit[x][y] && map[x][y] != '*') {
                visit[x][y] = true;

                if(map[x][y] == 'D') {
                    System.out.print(dis);
                    return ;
                }

                if(x + 1 < r && map[x + 1][y] != '*' && map[x + 1][y] != 'X') {
                    que.add(new Place(x + 1, y, dis + 1));
                }
                if(x - 1 > -1 && map[x - 1][y] != '*' && map[x - 1][y] != 'X') {
                    que.add(new Place(x - 1, y, dis + 1));
                }
                if(y + 1 < c && map[x][y + 1] != '*' && map[x][y + 1] != 'X') {
                    que.add(new Place(x, y + 1, dis + 1));
                }
                if(y - 1 > -1 && map[x][y - 1] != '*' && map[x][y - 1] != 'X') {
                    que.add(new Place(x, y - 1, dis + 1));
                }
            }
        }
        System.out.print("KAKTUS");
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