package 가장_먼_노드;

import java.util.*;

public class Solution {

    static List<Integer>[] graph;

    public int solution(int n, int[][] edge) {
        graph = new ArrayList[n + 1];
        for(int i = 1; i<=n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] vertex : edge) {
            graph[vertex[0]].add(vertex[1]);
            graph[vertex[1]].add(vertex[0]);
        }

        int max = 0;
        Map<Integer, Integer> disMap = new HashMap<>();

        boolean[] visit = new boolean[n + 1];
        Queue<Node> que = new LinkedList<>();
        que.add(new Node(1, 0));

        while(!que.isEmpty()) {
            Node node = que.poll();
            int index = node.index;
            int dis = node.dis;

            if(!visit[index]) {
                visit[index] = true;
                disMap.put(dis, disMap.getOrDefault(dis, 0) + 1);
                max = Math.max(max, dis);

                for(int next : graph[index]) {
                    if(!visit[next]) {
                        que.add(new Node(next, dis + 1));
                    }
                }
            }
        }

        return disMap.get(max);
    }

    static class Node {

        int index, dis;

        Node(int index, int dis) {
            this.index = index;
            this.dis = dis;
        }

    }

}
