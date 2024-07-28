package 투자의_귀재_배주형;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int h = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int[] dp = new int[y + 1];

        dp[0] = h;
        for(int i = 1; i<=y; i++) {
            dp[i] = dp[i - 1] * 105 / 100;
            if(i >= 3) {
                dp[i] = Math.max(dp[i], dp[i - 3] * 120 / 100);
            }
            if(i >= 5) {
                dp[i] = Math.max(dp[i], dp[i - 5] * 135 / 100);
            }
        }
        System.out.print(dp[y]);
    }

}
