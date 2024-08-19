package 그래프_탐색_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int n, m;
    static int[] dp;
    static List<Integer>[] graph;

    static void bfs(Node start) {
        boolean[] visit = new boolean[n + 1];
        Queue<Node> que = new LinkedList<>();
        que.add(start);

        while(!que.isEmpty()) {
            Node node = que.poll();
            int num = node.num;
            int phase = node.phase;

            if(1 == num) {
                if(-1 == dp[start.num]) {
                    dp[start.num] = phase;
                } else {
                    dp[start.num] = Math.min(dp[start.num], phase);
                }
                break;
            }

            if(!visit[num]) {
                visit[num] = true;
                for(int next : graph[num]) {
                    que.add(new Node(next, phase + 1));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        dp = new int[n + 1];
        graph = new ArrayList[n + 1];

        for(int i = 1; i<=n; i++) {
            if(i > 1) {
                dp[i] = 1000000000;
            }
            graph[i] = new ArrayList<>();
        }

        while(m-- > 0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int c1 = Integer.parseInt(st2.nextToken());
            int c2 = Integer.parseInt(st2.nextToken());
            graph[c1].add(c2);
            graph[c2].add(c1);
        }

        for(int i = 1; i<=n; i++) {
            bfs(new Node(i, 0));
        }

        int q = Integer.parseInt(br.readLine());
        while(q-- > 0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int c1 = Integer.parseInt(st2.nextToken());
            int c2 = Integer.parseInt(st2.nextToken());
            graph[c1].add(c2);
            graph[c2].add(c1);

            boolean[] visit = new boolean[n + 1];
            Queue<Node> que = new LinkedList<>();

            if(dp[c1] > dp[c2] + 1) {
                dp[c1] = dp[c2] + 1;
                que.add(new Node(c1, dp[c1]));
            }
            if(dp[c2] > dp[c1] + 1) {
                dp[c2] = dp[c1] + 1;
                que.add(new Node(c2, dp[c2]));
            }

            while(!que.isEmpty()) {
                Node node = que.poll();

                if(!visit[node.num]) {
                    visit[node.num] = true;

                    for(int next : graph[node.num]) {
                        dp[next] = Math.min(dp[next], node.phase + 1);
                        que.add(new Node(next, dp[next]));
                    }
                }
            }

            for(int i = 1; i<=n; i++) {
                sb.append(dp[i] == 1000000000 ? -1 : dp[i]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static class Node {

        int num, phase;

        Node(int num, int phase) {
            this.num = num;
            this.phase = phase;
        }

    }

}
