package 숨바꼭질;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int subin = Integer.parseInt(st.nextToken());
        int youngerBrother = Integer.parseInt(st.nextToken());

        if (subin == youngerBrother) {
            System.out.println(0);
            return;
        }

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(subin);
        int[] distance = new int[100001];
        Arrays.fill(distance, -1);
        distance[subin] = 0;

        while (!queue.isEmpty()) {
            int currentSubin = queue.poll();

            int[] movement = {1, -1, 2};

            for (int i = 0; i < 3; i++) {
                int nextSubin;

                if (movement[i] == 2) {
                    nextSubin = currentSubin * 2;
                } else {
                    nextSubin = currentSubin + movement[i];
                }

                if (nextSubin >= 0 && nextSubin < distance.length && distance[nextSubin] == -1) {
                    queue.offer(nextSubin);
                    distance[nextSubin] = distance[currentSubin] + 1;

                    if (nextSubin == youngerBrother) {
                        System.out.println(distance[nextSubin]);
                        return;
                    }
                }
            }
        }
    }
}