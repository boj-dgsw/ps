package 쉬운_계단_수;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][10];

        for(int i = 1; i<10; i++) {
            dp[1][i] = 1;
        }

        for(int i = 2; i<=n; i++) {
            for(int j = 0; j<10; j++) {
                if(j - 1 > -1) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= 1000000000;
                }
                if(j + 1 < 10) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= 1000000000;
                }
            }
        }

        int sum = 0;
        for(int i = 0; i<10; i++) {
            sum += dp[n][i];
            sum %= 1000000000;
        }
        System.out.print(sum);
    }

}
