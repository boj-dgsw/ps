package 캡틴_이다솜;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] tetrahedron = new int[780];
        int[] dp = new int[n + 1];
        List<Integer> tetrahedronList = new ArrayList<>();

        dp[1] = 1;
        for(int i = 2; i<=n; i++) {
            dp[i] = 1000000;
        }

        tetrahedron[1] = 1;
        for(int i = 2; i<780; i++) {
            tetrahedron[i] = tetrahedron[i - 1] + i;
        }

        tetrahedronList.add(1);
        for(int i = 2; i<780; i++) {
            tetrahedron[i] += tetrahedron[i - 1];
            if(tetrahedron[i] <= n) {
                tetrahedronList.add(tetrahedron[i]);
            } else {
                break;
            }
        }

        for(int coin : tetrahedronList) {
            for (int j = coin; j <= n; j++) {
                dp[j] = Math.min(dp[j], dp[j - coin] + 1);
            }
        }
        System.out.print(dp[n]);
    }

}
