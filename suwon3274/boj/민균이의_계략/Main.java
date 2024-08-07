package 민균이의_계략;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int max = 1;
        int[] dp = new int[n];
        int[] cards = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            cards[i] = Integer.parseInt(st.nextToken());
            int temp = 0;
            for(int j = i - 1; j>-1; j--) {
                if(cards[i] > cards[j]) {
                    temp = Math.max(temp, dp[j]);
                }
            }
            dp[i] = temp + 1;
            max = Math.max(max, dp[i]);
        }
        System.out.print(max);
    }

}
