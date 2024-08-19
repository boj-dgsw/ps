package BOJ_거리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n];
        String boj = br.readLine();

        for(int i = 1; i<n; i++) {
            char c = boj.charAt(i);
            char target = 'B' == c ? 'J' : 'O' == c ? 'B' : 'O';
            int min = Integer.MAX_VALUE;
            for(int j = i - 1; j>-1; j--) {
                if(target == boj.charAt(j) && dp[j] != 1000000000) {
                    int pow = (i - j) * (i - j);
                    min = Math.min(min, dp[j] + pow);
                }
            }
            dp[i] = min == Integer.MAX_VALUE ? 1000000000 : min;
        }
        System.out.print(dp[n - 1] == 1000000000 ? -1 : dp[n - 1]);
    }

}
