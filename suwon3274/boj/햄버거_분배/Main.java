package 햄버거_분배;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        String table = br.readLine();

        boolean[] eat = new boolean[n];
        int result = 0;
        for(int i = 0; i<n; i++) {
            if('P' == table.charAt(i)) {
                int start = Math.max(0, i - k);
                int end = Math.min(n - 1, i + k );

                for(int j = start; j<=end; j++) {
                    if('H' == table.charAt(j) && !eat[j]) {
                        result++;
                        eat[j] = true;
                        break;
                    }
                }
            }
        }
        System.out.print(result);
    }

}
