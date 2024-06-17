package RGB_거리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] costs;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        costs = new int[n][3];
        dp = new int[n][3];

        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<3; j++) {
                costs[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i<3; i++) {
            dp[0][i] = costs[0][i];
        }

        for(int i = 1; i<n; i++) {
            for(int j = 0; j<3; j++) {
                for(int k = 0; k<3; k++) {
                    if(j != k) {
                        if(dp[i][j] == 0) {
                            dp[i][j] = dp[i - 1][k] + costs[i][j];
                        } else {
                            dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                        }
                    }
                }
            }
        }

        int answer = Integer.MAX_VALUE;
        for(int i = 0; i<3; i++) {
            answer = Math.min(answer, dp[n - 1][i]);
        }
        System.out.print(answer);
    }

}
