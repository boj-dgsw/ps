package 최대_상승;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] prices = new int[n + 1];
        int[] dp = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n; i++) {
            prices[i] = Integer.parseInt(st.nextToken());
        }

        dp[1] = prices[1];
        for(int i = 2; i<=n; i++) {
            dp[i] = Math.min(prices[i], dp[i - 1]);
        }

        int max = 0;
        for(int i = 1; i<=n; i++) {
            max = Math.max(max, prices[i] - dp[i]);
        }
        System.out.print(max);
    }

}
