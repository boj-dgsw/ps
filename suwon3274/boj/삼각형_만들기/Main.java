package 삼각형_만들기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] straws = new int[n];

        for(int i = 0; i<n; i++) {
            straws[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(straws);

        int first = n - 1;
        int second = n - 2;

        for(int i = n - 3; i>-1; i--) {
            if(straws[i] + straws[second] > straws[first]) {
                System.out.print(straws[first] + straws[second] + straws[i]);
                return ;
            } else {
                first--;
                second--;
            }
        }

        System.out.print(-1);
    }

}
