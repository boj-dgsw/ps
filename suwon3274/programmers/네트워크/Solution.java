package 네트워크;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public int solution(int n, int[][] computers) {
        int answer = 0;

        List<Integer>[] network = new ArrayList[n];
        for(int i = 0; i<n; i++) {
            network[i] = new ArrayList<>();
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i != j && computers[i][j] == 1) {
                    network[i].add(j);
                    network[j].add(i);
                }
            }
        }

        boolean[] visit = new boolean[n];
        for(int i = 0; i<n; i++) {
            if(!visit[i]) {
                answer++;

                Queue<Integer> que = new LinkedList<>();
                que.add(i);

                while(!que.isEmpty()) {
                    int node = que.poll();

                    if(!visit[node]) {
                        visit[node] = true;

                        for(int next : network[node]) {
                            if(!visit[next]) {
                                que.add(next);
                            }
                        }
                    }
                }
            }
        }

        return answer;
    }

}