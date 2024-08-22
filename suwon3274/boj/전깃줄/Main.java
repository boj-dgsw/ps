package 전깃줄;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n];
        ElectricWire[] electricWires = new ElectricWire[n];

        for(int i = 0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            electricWires[i] = new ElectricWire(left, right);
            dp[i] = 1;
        }
        Arrays.sort(electricWires, (o1, o2) -> {
            if(o1.left == o2.left) {
                return o1.right - o2.right;
            }
            return o1.left - o2.left;
        });

        int result = 0;
        for(int i = 0; i<n; i++) {
            int currentLeft = electricWires[i].left;
            int currentRight = electricWires[i].right;
            int max = 0;
            for(int j = i - 1; j>-1; j--) {
                if(currentLeft >= electricWires[j].left && currentRight >= electricWires[j].right) {
                    max = Math.max(max, dp[j]);
                }
            }
            dp[i] += max;
            result = Math.max(result, dp[i]);
        }
        System.out.print(n - result);
    }

    static class ElectricWire {

        int left, right;

        ElectricWire(int left, int right) {
            this.left = left;
            this.right = right;
        }

    }

}
