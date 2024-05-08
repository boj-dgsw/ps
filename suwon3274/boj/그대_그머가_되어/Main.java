package 그대_그머가_되어;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st2.nextToken());
        int m = Integer.parseInt(st2.nextToken());

        graph = new List[n + 1];
        for(int i = 1; i<=n; i++) {
            graph[i] = new ArrayList<>();
        }

        while(m-- > 0) {
            StringTokenizer st3 = new StringTokenizer(br.readLine());
            int c1 = Integer.parseInt(st3.nextToken());
            int c2 = Integer.parseInt(st3.nextToken());
            graph[c1].add(c2);
            graph[c2].add(c1);
        }

        boolean[] visit = new boolean[n + 1];
        Queue<Substitution> que = new LinkedList<>();
        que.add(new Substitution(a, 0));

        while(!que.isEmpty()) {
            Substitution substitution = que.poll();
            int node = substitution.node;
            int dis = substitution.dis;

            if(!visit[node]) {
                visit[node] = true;

                if(b == node) {
                    System.out.print(dis);
                    return ;
                }

                for(int next : graph[node]) {
                    que.add(new Substitution(next, dis + 1));
                }
            }
        }

        System.out.print(-1);
    }

    static class Substitution {

        int node, dis;

        Substitution(int node, int dis) {
            this.node = node;
            this.dis = dis;
        }

    }

}
