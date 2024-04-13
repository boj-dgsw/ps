import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] park = new int[n][n];

        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<n; j++) {
                park[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result = 0;
        boolean isEnd = false;
        while(!isEnd) {
            isEnd = true;
            List<Place> list = new ArrayList<>();
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    if(park[i][j] > 0) {
                        isEnd = false;
                        int cnt = 0;
                        if(i + 1 < n && park[i + 1][j] == 0) {
                            cnt++;
                        }
                        if(i - 1 > -1 && park[i - 1][j] == 0) {
                            cnt++;
                        }
                        if(j + 1 < n && park[i][j + 1] == 0) {
                            cnt++;
                        }
                        if(j - 1 > -1 && park[i][j - 1] == 0) {
                            cnt++;
                        }
                        list.add(new Place(i, j, cnt));
                    }
                }
            }

            for(Place p : list) {
                park[p.x][p.y] = Math.max(0, park[p.x][p.y] - p.cnt);
            }
            result++;
        }
        System.out.print(result - 1);
    }

    static class Place {

        int x, y, cnt;

        Place(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }

    }

}
