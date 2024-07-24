package 떡_먹는_호랑이;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        for(int i = 1; i<k; i++) {
            for(int j = i; j<k; j++) {
                int[] dp = new int[d];
                dp[0] = i;
                dp[1] = j;
                for(int l = 2; l<d; l++) {
                    dp[l] = dp[l - 1] + dp[l - 2];
                }
                if(k == dp[d - 1]) {
                    System.out.println(i);
                    System.out.print(j);
                    return ;
                }
            }
        }
    }

}
