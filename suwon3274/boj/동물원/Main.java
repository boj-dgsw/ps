package 동물원;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][3];

        dp[1][0] = dp[1][1] = dp[1][2] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % 9901 + dp[i - 1][2]) % 99901;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        }

        int result = ((dp[n][0] + dp[n][1]) % 9901 + dp[n][2]) % 9901;
        System.out.print(result);
    }

}
