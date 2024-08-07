package 정수_삼각형;

public class Solution {

    public int solution(int[][] triangle) {
        int n = triangle.length;
        int[][] dp = new int[n][];

        for(int i = 0; i<n; i++) {
            dp[i] = new int[i + 1];
        }

        dp[0][0] = triangle[0][0];
        for(int i = 1; i<n; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
            for(int j = 1; j<i; j++) {
                dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }

        int answer = 0;
        for(int i = 0; i<n; i++) {
            answer = Math.max(answer, dp[n - 1][i]);
        }
        return answer;
    }

}
