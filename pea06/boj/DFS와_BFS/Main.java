package DFS와_BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int node = Integer.parseInt(st.nextToken());
        int edge = Integer.parseInt(st.nextToken());
        int startNode = Integer.parseInt(st.nextToken());

        int[][] graph = new int[node + 1][node + 1];
        for (int i = 0; i < edge; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a][b] = graph[b][a] = 1;
        }

        int[] visited = new int[node + 1];
        dfs(graph, startNode, node, visited);
        System.out.println();
        bfs(graph, startNode, node);
    }

    public static void dfs(int[][] graph, int startNode, int nodeCount, int[] visited) {
        visited[startNode] = 1;
        System.out.print(startNode + " ");
        for(int i = 0 ; i <= nodeCount ; i++) {
            if(graph[startNode][i] == 1 && visited[i] == 0)
                dfs(graph, i, nodeCount, visited);
        }
    }

    public static void bfs(int[][] graph, int startNode, int nodeCount) {
        Queue<Integer> queue = new LinkedList<>();
        int[] visited = new int[nodeCount + 1];
        queue.offer(startNode);
        visited[startNode] = 1;
        while (!queue.isEmpty()) {
            int poll = queue.poll();
            System.out.print(poll + " ");
            for (int i = 1; i <= nodeCount; i++) {
                if (graph[poll][i] == 1 && visited[i] == 0) {
                    queue.offer(i);
                    visited[i] = 1;
                }
            }
        }
    }
}
