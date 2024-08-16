package 돌_게임_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        boolean[] dp = new boolean[n + 5];

        dp[1] = true;
        dp[2] = false;
        dp[3] = true;
        dp[4] = true;
        for(int i = 5; i<=n; i++) {
            dp[i] = dp[i - 1] && dp[i - 3] && dp[i - 4] ? false : true;
        }

        System.out.print(dp[n] ? "SK" : "CY");
    }

}
