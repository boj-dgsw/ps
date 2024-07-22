package 스티커;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[][] arr = new int[2][n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            for(int i = 0; i<n; i++) {
                arr[0][i] = Integer.parseInt(st.nextToken());
                arr[1][i] = Integer.parseInt(st2.nextToken());
            }

            int max = 0;
            int[][] dp = new int[2][n];
            dp[0][0] = arr[0][0];
            dp[1][0] = arr[1][0];
            max = Math.max(dp[0][0], dp[1][0]);

            for(int i = 1; i<n; i++) {
                if(i == 1) {
                    dp[0][1] = dp[1][0] + arr[0][1];
                    dp[1][1] = dp[0][0] + arr[1][1];
                    max = Math.max(max, Math.max(dp[0][i], dp[1][i]));

                    continue;
                }

                dp[0][i] = Math.max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
                dp[1][i] = Math.max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
                max = Math.max(max, Math.max(dp[0][i], dp[1][i]));
            }

            sb.append(max).append("\n");
        }
        System.out.print(sb);
    }

}
