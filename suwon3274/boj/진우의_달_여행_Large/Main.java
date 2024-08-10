package 진우의_달_여행_Large;

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
        int[][] fuels = new int[n + 1][m + 1];
        int[][][] dp = new int[n + 1][m + 1][4];

        for(int i = 1; i<=n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int j = 1; j<=m; j++) {
                fuels[i][j] = Integer.parseInt(st2.nextToken());
                for(int k = 1; k<=3; k++) {
                    dp[i][j][k] = fuels[i][j];
                }
            }
        }

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(1 == j) {
                    dp[i][j][1] += Math.min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]);
                    dp[i][j][2] += dp[i - 1][j][1];
                    dp[i][j][3] = 1000000;
                } else if(m == j) {
                    dp[i][j][1] = 1000000;
                    dp[i][j][2] += dp[i - 1][j][3];
                    dp[i][j][3] += Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
                } else {
                    dp[i][j][1] += Math.min(dp[i - 1][j + 1][2], dp[i - 1][j + 1][3]);
                    dp[i][j][2] += Math.min(dp[i - 1][j][1], dp[i - 1][j][3]);
                    dp[i][j][3] += Math.min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
                }
            }
        }

        int min = Integer.MAX_VALUE;
        for(int i = 1; i<=m; i++) {
            for(int j = 1; j<=3; j++) {
                min = Math.min(min, dp[n][i][j]);
            }
        }
        System.out.print(min);
    }

}
