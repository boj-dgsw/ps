package 카드_구매하기_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] packs = new int[n + 1];
        int[] dp = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n; i++) {
            packs[i] = Integer.parseInt(st.nextToken());
            dp[i] = Integer.MAX_VALUE;
        }

        for(int i = 1; i<=n; i++) {
            dp[i] = packs[i];
            for(int j = 1; j<i; j++) {
                dp[i] = Math.min(dp[i], dp[j] * (i / j) + dp[i % j]);
            }
        }
        System.out.print(dp[n]);
    }

}
