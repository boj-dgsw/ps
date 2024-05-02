package 트리;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Integer>[] child;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        child = new List[n];
        for(int i = 0; i<n; i++) {
            child[i] = new ArrayList<>();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if(-1 != parent) {
                child[parent].add(i);
            }
        }

        int delete = Integer.parseInt(br.readLine());
        Queue<Integer> que = new LinkedList<>();
        que.add(delete);

        boolean[] deleted = new boolean[n];
        while(!que.isEmpty()) {
            int node = que.poll();

            if(!deleted[node]) {
                deleted[node] = true;
                que.addAll(child[node]);
            }
        }

        int result = 0;
        for(int i = 0; i<n; i++) {
            if(!deleted[i]) {
                for(int c : child[i]) {
                    if(!deleted[c]) {
                        result--;
                        break;
                    }
                }
                result++;
            }
        }
        System.out.print(result);
    }

}
