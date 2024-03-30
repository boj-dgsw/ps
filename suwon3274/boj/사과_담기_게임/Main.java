package 사과_담기_게임;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int j = Integer.parseInt(br.readLine());
        int x = 1, y = m;

        int result = 0;
        for(int i = 0; i<j; i++) {
            int gap = 0;
            int apple = Integer.parseInt(br.readLine());
            if(x > apple) {
                gap = apple - x;
            } else if(y < apple) {
                gap = apple - y;
            }
            x += gap;
            y += gap;
            result += Math.abs(gap);

            if(x < 1) {
                x = 1;
                y = m;
            } else if(y > n) {
                y = n;
                x = y - m + 1;
            }
        }
        System.out.print(result);
    }

}
