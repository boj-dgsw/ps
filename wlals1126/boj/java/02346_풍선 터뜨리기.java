import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            deque.push(i);
        }

        int [] arr = new int [N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        while (deque.size() > 1) {
            int target = deque.pollLast();
            bw.write(String.valueOf(target) + " ");
            int moving = arr[target - 1];
            if (moving < 0) {
                while (moving < 0) {
                    moving++;
                    deque.addLast(deque.pollFirst());
                }
            } else {
                moving--;
                while (moving > 0) {
                    moving--;
                    deque.addFirst(deque.pollLast());
                }
            }
        }

        bw.write(String.valueOf(deque.peek()));
        bw.flush();
        bw.close();
    }
}
