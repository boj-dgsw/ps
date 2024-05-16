package 수익;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(0 == n) {
                break;
            }

            int[] revenues = new int[n + 1];
            long[] dp = new long[n + 1];
            long max = Long.MIN_VALUE;
            for(int i = 1; i<=n; i++) {
                revenues[i] = Integer.parseInt(br.readLine());
                dp[i] = Math.max(dp[i - 1], 0) + revenues[i];
                max = Math.max(max, dp[i]);
            }

            sb.append(max).append("\n");
        }
        System.out.print(sb);
    }

}
