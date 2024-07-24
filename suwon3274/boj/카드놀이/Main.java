package 카드놀이;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] cards = new int[n + 1];

        for(int i = 0; i<n; i++) {
            cards[Integer.parseInt(br.readLine())] = i;
        }

        int result = 0;
        for(int i = 1; i<=n; i++) {
            if(cards[i - 1] > cards[i]) {
                result++;
            }
        }
        System.out.print(result);
    }

}
