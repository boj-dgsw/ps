package 바이러스;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int node = Integer.parseInt(br.readLine());
        int edge = Integer.parseInt(br.readLine());

        int[][] graph = new int[node + 1][node + 1];

        StringTokenizer st;
        for (int i = 0; i < edge; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a][b] = graph[b][a] = 1;
        }

        int cnt = 0;
        int[] visited = new int[node + 1];
        Stack<Integer> stack = new Stack<>();
        visited[1] = 1;
        stack.add(1);
        while (!stack.isEmpty()){
            int pop = stack.pop();

            for (int i = 1; i <= node; i++) {
                if (graph[pop][i] == 1 && visited[i] == 0) {
                    stack.push(i);
                    visited[i] = 1;
                    cnt++;
                }
            }
        }

        System.out.print(cnt);
    }

}
