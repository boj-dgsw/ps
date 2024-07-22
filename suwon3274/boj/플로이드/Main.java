package 플로이드;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static Map<Integer, Integer>[] graph;
    static long[][] distances;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        distances = new long[n + 1][n + 1];
        graph = new Map[n + 1];
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                distances[i][j] = Long.MAX_VALUE;
            }
            graph[i] = new HashMap<>();
        }

        while(m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int destination = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            if(graph[start].containsKey(destination)) {
                graph[start].put(destination, Math.min(graph[start].get(destination), weight));
            } else {
                graph[start].put(destination, weight);
            }
        }

        for(int i = 1; i<=n; i++) {
            distances[i][i] = 0;
            PriorityQueue<Node> que = new PriorityQueue<>(Comparator.comparingLong(no -> no.weight));
            que.add(new Node(i, 0));

            while(!que.isEmpty()) {
                Node node = que.poll();
                int num = node.num;
                long weight = node.weight;

                if(distances[i][num] < weight) {
                    continue;
                }

                for(Map.Entry<Integer, Integer> next : graph[num].entrySet()) {
                    if(distances[i][next.getKey()] > weight + next.getValue()) {
                        distances[i][next.getKey()] = weight + next.getValue();
                        que.add(new Node(next.getKey(), distances[i][next.getKey()]));
                    }
                }
            }
        }

        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                sb.append(distances[i][j] == Long.MAX_VALUE ? 0 : distances[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

    static class Node {

        int num;
        long weight;

        Node(int num, long weight) {
            this.num = num;
            this.weight = weight;
        }

    }

}
