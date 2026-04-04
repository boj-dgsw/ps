package 서버_증설_회수;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        //1대의 서버는 m명을 감당가능.
        //k는 살아있는 기간
        int[][] dp = new int[players.length][2];
        //index 0은 현재 가용되고 있는 서버 개수
        //index 1은 해당 시점에 새로이 가용시킨 서버 개수
        for(int i = 0; i<players.length; i++) {
            int prev = i - 1 >= 0 ? dp[i - 1][0] : 0;
            int dead = i - k >= 0 ? dp[i - k][1] : 0;
            dp[i][0] = prev - dead;

            int proper = players[i] / m;
            if(dp[i][0] < proper) {
                dp[i][1] = proper - dp[i][0];
                dp[i][0] = proper;
            }
            System.out.println(dp[i][0] + " " + dp[i][0]);
        }
        for(int i = 0; i<players.length; i++) {
            answer += dp[i][1];
        }

        return answer;
    }
}
