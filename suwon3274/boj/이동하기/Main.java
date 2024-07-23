package 이동하기;

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
        int[][] candies = new int[n][m];

        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++) {
                candies[i][j] = Integer.parseInt(st2.nextToken());
            }
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int r1c = 0, rc1 = 0, r1c1 = 0;
                if(i - 1 > -1) {
                    r1c = dp[i - 1][j];
                }
                if(j - 1 > -1) {
                    rc1 = dp[i][j - 1];
                }
                if(i - 1 > -1 && j - 1 > -1) {
                    r1c1 = dp[i - 1][j - 1];
                }
                dp[i][j] = Math.max(r1c1, Math.max(r1c, rc1)) + candies[i][j];
            }
        }

        System.out.print(dp[n - 1][m - 1]);
    }

}
