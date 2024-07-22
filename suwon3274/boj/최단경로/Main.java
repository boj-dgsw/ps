package 최단경로;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Node>[] graph;
    static int[] distances;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());

        distances = new int[v + 1];
        graph = new List[v + 1];
        for(int i = 1; i<=v; i++) {
            distances[i] = Integer.MAX_VALUE;
            graph[i] = new ArrayList<>();
        }

        while(e-- > 0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st2.nextToken());
            int destination = Integer.parseInt(st2.nextToken());
            int weight = Integer.parseInt(st2.nextToken());
            graph[start].add(new Node(destination, weight));
        }

        distances[k] = 0;
        PriorityQueue<Node> que = new PriorityQueue<>(Comparator.comparingInt(n -> n.weight));
        que.add(new Node(k, 0));

        while(!que.isEmpty()) {
            Node node = que.poll();
            int num = node.num;
            int weight = node.weight;

            if(distances[num] < weight) {
                continue;
            }

            for(Node next : graph[num]) {
                if(distances[next.num] > weight + next.weight) {
                    distances[next.num] = weight + next.weight;
                    que.add(new Node(next.num, distances[next.num]));
                }
            }
        }

        for(int i = 1; i<=v; i++) {
            sb.append(Integer.MAX_VALUE == distances[i] ? "INF" : distances[i]).append("\n");
        }
        System.out.print(sb);
    }

    static class Node {

        int num, weight;

        Node(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }

    }

}
