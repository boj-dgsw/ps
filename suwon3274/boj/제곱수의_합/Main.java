package 제곱수의_합;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int[] dp;

    static int getMin(int number) {
        int sqrt = (int) Math.sqrt(number);
        if(dp[number] != 0) {
            return dp[number];
        } else {
            int min = Integer.MAX_VALUE;
            for(int i = 0; i<sqrt; i++) {
                int s = (sqrt - i) * (sqrt - i);
                min = Math.min(min, dp[s] + getMin(number - s));
            }
            return dp[number] = min;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        dp = new int[n + 1];

        for(int i = 1; i*i<=n; i++) {
            dp[i * i] = 1;
        }

        System.out.println(getMin(n));
    }

}
