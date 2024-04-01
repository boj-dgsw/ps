package 폭죽쇼;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        boolean[] isOnFire = new boolean[c + 1];

        for(int i = 0; i<n; i++) {
            int fire = Integer.parseInt(br.readLine());
            for(int j = fire; j<=c; j+=fire) {
                isOnFire[j] = true;
            }
        }

        int answer = 0;
        for(boolean b : isOnFire) {
            if(b) {
                answer++;
            }
        }
        System.out.print(answer);
    }

}
