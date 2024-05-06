package 주식;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] prices = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<n; i++) {
                prices[i] = Integer.parseInt(st.nextToken());
            }

            long result = 0;
            int peak = prices[n - 1];
            int streak = 0;
            int minusSum = 0;
            for(int i = n - 2; i>-1; i--) {
                if(peak > prices[i]) {
                    streak++;
                    minusSum += prices[i];
                } else {
                    result += (long) peak * streak - minusSum;
                    peak = prices[i];
                    streak = minusSum = 0;
                }
            }

            sb.append(result + (long) peak * streak - minusSum).append("\n");
        }

        System.out.print(sb);
    }

}
