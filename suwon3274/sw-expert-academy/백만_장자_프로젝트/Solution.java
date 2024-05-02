import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for(int z = 1; z<=t; z++) {
            sb.append("#").append(z).append(" ");
            int n = Integer.parseInt(br.readLine());
            int[] prices = new int[n + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<n; i++) {
                prices[i] = Integer.parseInt(st.nextToken());
            }

            long profit = 0;
            int high = prices[n - 1];
            int minus = 0;
            int streak = 0;
            for(int i = n - 2; i>-1; i--) {
                if(high > prices[i]) {
                    minus += prices[i];
                    streak++;
                } else {
                    profit += (long) high * streak - minus;
                    high = prices[i];
                    streak = 0;
                    minus = 0;
                }
            }
            profit += (long) high * streak - minus;
            sb.append(profit).append("\n");
        }
        System.out.print(sb);
    }

}
