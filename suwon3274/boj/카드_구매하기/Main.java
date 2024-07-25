package 카드_구매하기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        int[] packs = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n; i++) {
            packs[i] = Integer.parseInt(st.nextToken());
        }

        dp[1] = packs[1];
        for(int i = 2; i<=n; i++) {
            dp[i] = packs[i];
            for(int j = 1; j<i; j++) {
                dp[i] = Math.max(dp[i], dp[j] + dp[i - j]);
            }
        }
        System.out.print(dp[n]);
    }

}
