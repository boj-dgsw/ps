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

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cnt = 0;
            int w = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            if(w == 0 && h == 0) {
                break;
            }

            int[][] map = new int[h][w];
            for(int i = 0; i<h; i++) {
                StringTokenizer st2 = new StringTokenizer(br.readLine());
                for(int j = 0; j<w; j++) {
                    map[i][j] = Integer.parseInt(st2.nextToken());
                }
            }

            boolean[][] visit = new boolean[h][w];
            for(int i = 0; i<h; i++) {
                for(int j = 0; j<w; j++) {
                    if(map[i][j] == 1 && !visit[i][j]) {
                        cnt++;
                        Queue<Place> que = new LinkedList<>();
                        que.add(new Place(i, j));

                        while(!que.isEmpty()) {
                            Place place = que.poll();
                            int x = place.x;
                            int y = place.y;

                            if(!visit[x][y]) {
                                visit[x][y] = true;

                                if(x + 1 < h && map[x + 1][y] == 1) {
                                    que.add(new Place(x + 1, y));
                                }
                                if(x - 1 > -1 && map[x - 1][y] == 1) {
                                    que.add(new Place(x - 1, y));
                                }
                                if(y + 1 < w && map[x][y + 1] == 1) {
                                    que.add(new Place(x, y + 1));
                                }
                                if(y - 1 > -1 && map[x][y - 1] == 1) {
                                    que.add(new Place(x, y - 1));
                                }
                                if(x + 1 < h && y + 1 < w && map[x + 1][y + 1] == 1) {
                                    que.add(new Place(x + 1, y + 1));
                                }
                                if(x + 1 < h && y - 1 > -1 && map[x + 1][y - 1] == 1) {
                                    que.add(new Place(x + 1, y - 1));
                                }
                                if(x - 1 > -1 && y + 1 < w && map[x - 1][y + 1] == 1) {
                                    que.add(new Place(x - 1, y + 1));
                                }
                                if(x - 1 > -1 && y - 1 > -1 && map[x - 1][y - 1] == 1) {
                                    que.add(new Place(x - 1, y - 1));
                                }
                            }
                        }
                    }
                }
            }
            sb.append(cnt).append("\n");
        }

        System.out.print(sb);
    }

    static class Place {

        int x, y;

        Place(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}