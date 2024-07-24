package 점프_점프;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n];
        int[] maze = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            maze[i] = Integer.parseInt(st.nextToken());
        }

        dp[0] = 0;
        boolean[] visit = new boolean[n];
        Queue<Integer> que = new LinkedList<>();
        que.add(0);

        while(!que.isEmpty()) {
            int current = que.poll();
            if(n - 1 == current) {
                System.out.print(dp[current]);
                return ;
            }
            for(int i = 1; i<=maze[current]; i++) {
                if(current + i < n && !visit[current + i]) {
                    visit[current + i] = true;
                    dp[current + i] = dp[current] + 1;
                    if(current + i < n) {
                        que.add(current + i);
                    }
                }
            }
        }
        System.out.print(-1);
    }

}
