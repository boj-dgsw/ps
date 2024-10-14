class Solution {

    static int[] dp;

    public int fib(int n) {
        if(n == 0) {
            return 0;
        }

        dp = new int[n + 1];
        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        return f(n);
    }

    public int f(int n) {
        if(dp[n] != Integer.MAX_VALUE) {
            return dp[n];
        }
        return dp[n] = f(n - 1) + f(n - 2);
    }
}
