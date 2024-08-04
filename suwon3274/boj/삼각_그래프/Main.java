package 삼각_그래프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int cnt = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) {
                break;
            }

            int[][] nodes = new int[n][3];
            int[][] dp = new int[n][3];

            for(int i = 0; i<n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j = 0; j<3; j++) {
                    nodes[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            dp[0][0] = 1000000000;
            dp[0][1] = nodes[0][1];
            dp[0][2] = dp[0][1] + nodes[0][2];
            for(int i = 1; i<n; i++) {
                dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1]) + nodes[i][0];
                dp[i][1] = Math.min(dp[i - 1][0], Math.min(dp[i - 1][1], Math.min(dp[i - 1][2], dp[i][0]))) + nodes[i][1];
                dp[i][2] = Math.min(dp[i - 1][1], Math.min(dp[i - 1][2], dp[i][1])) + nodes[i][2];
            }
            sb.append(cnt++).append(". ").append(dp[n - 1][1]).append("\n");
        }
        System.out.print(sb);
    }

}
