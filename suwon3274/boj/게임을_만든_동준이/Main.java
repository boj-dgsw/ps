package 게임을_만든_동준이;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] levels = new int[n];

        for(int i = 0; i<n; i++) {
            levels[i] = Integer.parseInt(br.readLine());
        }

        int result = 0;
        for(int i = n - 2; i>-1; i--) {
            int lastLevel = levels[i + 1];

            if(lastLevel <= levels[i]) {
                result += levels[i] - lastLevel + 1;
                levels[i] = lastLevel - 1;
            }
        }
        System.out.print(result);
    }

}