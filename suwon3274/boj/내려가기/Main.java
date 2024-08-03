package 내려가기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] numbers = new int[n][3];
        int[][][] dp = new int[2][n][3];

        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<3; j++) {
                numbers[i][j] = Integer.parseInt(st.nextToken());
                dp[0][i][j] = dp[1][i][j] = numbers[i][j];
            }
        }

        for(int i = 1; i<n; i++) {
            dp[0][i][0] += Math.max(dp[0][i - 1][0], dp[0][i - 1][1]);
            dp[1][i][0] += Math.min(dp[1][i - 1][0], dp[1][i - 1][1]);

            dp[0][i][1] += Math.max(dp[0][i - 1][0], Math.max(dp[0][i - 1][1], dp[0][i - 1][2]));
            dp[1][i][1] += Math.min(dp[1][i - 1][0], Math.min(dp[1][i - 1][1], dp[1][i - 1][2]));

            dp[0][i][2] += Math.max(dp[0][i - 1][1], dp[0][i - 1][2]);
            dp[1][i][2] += Math.min(dp[1][i - 1][1], dp[1][i - 1][2]);
        }

        int max = 0, min = Integer.MAX_VALUE;
        for(int i = 0; i<3; i++) {
            max = Math.max(max, dp[0][n - 1][i]);
            min = Math.min(min, dp[1][n - 1][i]);
        }
        System.out.print(max + " " + min);
    }

}
