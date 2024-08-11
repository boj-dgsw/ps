package 자원_캐기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][m];
        int[][] map = new int[n][m];

        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++) {
                map[i][j] = Integer.parseInt(st2.nextToken());
                if(0 == i && 0 == j) {
                    dp[0][0] = map[0][0];
                } else if(0 == i) {
                    dp[0][j] = dp[0][j - 1] + map[0][j];
                } else if(0 == j) {
                    dp[i][0] = dp[i - 1][0] + map[i][0];
                }
            }
        }

        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
            }
        }
        System.out.print(dp[n - 1][m - 1]);
    }

}
