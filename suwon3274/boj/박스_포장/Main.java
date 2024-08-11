package 박스_포장;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n];
        int[] boxes = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            boxes[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i<n; i++) {
            int max = 0;
            for(int j = i - 1; j>-1; j--) {
                if(boxes[i] > boxes[j]) {
                    max = Math.max(max, dp[j]);
                }
            }
            dp[i] = max + 1;
        }

        int max = 1;
        for(int i = 1; i<n; i++) {
            max = Math.max(max, dp[i]);
        }
        System.out.print(max);
    }

}
