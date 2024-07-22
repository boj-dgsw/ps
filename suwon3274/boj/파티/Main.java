package 파티;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Node>[] graph;
    static int[][] distances;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        distances = new int[n + 1][n + 1];
        graph = new List[n + 1];
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                distances[i][j] = Integer.MAX_VALUE;
            }
            graph[i] = new ArrayList<>();
        }

        while(m-- > 0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st2.nextToken());
            int destination = Integer.parseInt(st2.nextToken());
            int weight = Integer.parseInt(st2.nextToken());
            graph[start].add(new Node(destination, weight));
        }

        for(int i = 1; i<=n; i++) {
            distances[i][i] = 0;
            PriorityQueue<Node> que = new PriorityQueue<>(Comparator.comparingInt(no -> no.weight));
            que.add(new Node(i, 0));

            while(!que.isEmpty()) {
                Node node = que.poll();
                int num = node.num;
                int weight = node.weight;

                if(distances[i][num] < weight) {
                    continue;
                }

                for(Node next : graph[num]) {
                    if(distances[i][next.num] > weight + next.weight) {
                        distances[i][next.num] = weight + next.weight;
                        que.add(new Node(next.num, distances[i][next.num]));
                    }
                }
            }
        }

        int max = 0;
        for(int i = 1; i<=n; i++) {
            max = Math.max(max, distances[i][x] + distances[x][i]);
        }
        System.out.print(max);
    }

    static class Node {

        int num, weight;

        Node(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }

    }

}
