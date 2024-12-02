package AarrowB;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*16953*/
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Integer.parseInt(st.nextToken());
        long b = Integer.parseInt(st.nextToken());

        //bfs
        Queue<Long> queue = new LinkedList<>();
        queue.add(a*2);
        queue.add((a*10)+1);

        int answer = 1;
        while (!queue.isEmpty()) {
            answer++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                long cur = queue.poll();
                if (cur>b) continue;
                if (cur==b) {
                    System.out.println(answer);
                    return;
                }

                queue.add(cur*2);
                queue.add((cur*10)+1);
            }
        }

        System.out.println(-1);

        //top-down
/*        int answer = 1;
        while (true) {
            if (a==b) {
                System.out.println(answer);
                return;
            } else if (a > b) {
                System.out.println(-1);
                return;
            }
            if (b%2==0) {
                b/=2;
            } else {
                String tmp = String.valueOf(b);
                if (tmp.charAt(tmp.length() - 1) == '1') {
                    tmp = tmp.substring(0, tmp.length() - 1);
                    b = Integer.parseInt(tmp);
                } else {
                    System.out.println(-1);
                    return;
                }
            }
            answer++;
        }*/
    }
}
