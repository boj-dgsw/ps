package 가장_긴_감소하는_부분_수열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n];
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            dp[i] = 1;
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = n - 2; i>=0; i--) {
            int max = 0;
            for(int j = i + 1; j<n; j++) {
                if(arr[j] < arr[i]) {
                    max = Math.max(max, dp[j]);
                }
            }
            dp[i] += max;
        }

        int max = dp[0];
        for(int i = 1; i<n; i++) {
            max = Math.max(max, dp[i]);
        }
        System.out.print(max);
    }

}
