package 새끼치기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 4][2];

        dp[1][0] = 0;
        dp[1][1] = 1;

        dp[2][0] = 1;
        dp[2][1] = 2;

        dp[3][0] = 2;
        dp[3][1] = 4;

        dp[4][0] = 4;
        dp[4][1] = 7;
        for(int i = 5; i<=n; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i][0] * 2;

            if(i % 2 == 0) {
                dp[i][1] -= dp[i - 3][0] + dp[i - 4][0];
            }
        }
        System.out.print(dp[n][1]);
    }

}
