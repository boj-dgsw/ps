package n단_논법;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int index = 0;
        Map<Character, Integer> indexMap = new HashMap<>();
        int n = Integer.parseInt(br.readLine());

        graph = new List[n * 2];
        for(int i = 0; i<n*2; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int i = 0; i<n; i++) {
            String s = br.readLine();
            char a = s.charAt(0);
            char b = s.charAt(5);

            if(!indexMap.containsKey(a)) {
                indexMap.put(a, index++);
            }
            if(!indexMap.containsKey(b)) {
                indexMap.put(b, index++);
            }

            graph[indexMap.get(a)].add(indexMap.get(b));
        }

        int m = Integer.parseInt(br.readLine());
        while(m-->0) {
            String s = br.readLine();
            boolean isTrue = false;
            if(indexMap.containsKey(s.charAt(0)) && indexMap.containsKey(s.charAt(5))) {
                int a = indexMap.get(s.charAt(0));
                int b = indexMap.get(s.charAt(5));

                Queue<Integer> que = new LinkedList<>();
                que.add(a);

                while(!que.isEmpty()) {
                    int node = que.poll();

                    if(b == node) {
                        isTrue = true;
                        break;
                    }

                    que.addAll(graph[node]);
                }
            }

            sb.append(isTrue ? "T" : "F").append("\n");
        }

        System.out.print(sb);
    }

}
