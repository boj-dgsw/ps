package 이름_궁합;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] stroke = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
        String a = br.readLine();
        String b = br.readLine();
        int length = a.length() * 2;

        int[][] dp = new int[length][];
        for(int i = 1; i<length; i++) {
            dp[i] = new int[i + 2];
        }

        for(int i = 0; i<a.length(); i++) {
            dp[length - 1][i * 2 + 1] = stroke[a.charAt(i) - 'A'];
        }
        for(int i = 1; i<=b.length(); i++) {
            dp[length - 1][i * 2] = stroke[b.charAt(i - 1) - 'A'];
        }

        for(int i = length - 2; i>0; i--) {
            for(int j = 1; j<dp[i].length; j++) {
                dp[i][j] = (dp[i + 1][j] + dp[i + 1][j + 1]) % 10;
            }
        }
        System.out.print("" + dp[1][1] + dp[1][2]);
    }

}
