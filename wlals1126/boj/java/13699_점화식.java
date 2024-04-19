import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] dp = new long[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int left = 0; left < i; left++) {
                int right = i - 1 - left;
                dp[i] += dp[left] * dp[right];
            }
        }

        System.out.println(dp[n]);
    }
}
