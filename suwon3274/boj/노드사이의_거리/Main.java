package 노드사이의_거리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Node>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        graph = new List[n + 1];
        for(int i = 1; i<=n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 1; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st2.nextToken());
            int n2 = Integer.parseInt(st2.nextToken());
            int dis = Integer.parseInt(st2.nextToken());

            graph[n1].add(new Node(n2, dis));
            graph[n2].add(new Node(n1, dis));
        }

        while(m-->0) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st2.nextToken());
            int n2 = Integer.parseInt(st2.nextToken());

            boolean[] visit = new boolean[n + 1];
            Queue<Node> que = new LinkedList<>();
            que.add(new Node(n1, 0));

            while(!que.isEmpty()) {
                Node node = que.poll();
                int value = node.value;
                int dis = node.dis;

                if(n2 == value) {
                    sb.append(dis).append("\n");
                    break;
                }

                if(!visit[value]) {
                    visit[value] = true;

                    for(Node next : graph[value]) {
                        que.add(new Node(next.value, dis + next.dis));
                    }
                }
            }
        }
        System.out.print(sb);
    }

    static class Node {

        int value, dis;

        Node(int value, int dis) {
            this.value = value;
            this.dis = dis;
        }

    }

}
