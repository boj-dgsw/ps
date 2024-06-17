package 정수_삼각형;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] dp;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        dp = new int[n][n];
        arr = new int[n][];
        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = new int[i + 1];
            for(int j = 0; j<arr[i].length; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i<n; i++) {
            dp[n - 1][i] = arr[n - 1][i];
        }

        for(int i = n - 2; i>=0; i--) {
            for(int j = 0; j<arr[i].length; j++) {
                dp[i][j] = Math.max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
            }
        }

        System.out.print(dp[0][0]);
    }

}
