import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

    static int[] cardValues = new int[12];

    static void init() {
        for(int i = 2; i<10; i++) {
            cardValues[i] = 4;
        }
        cardValues[10] = 16;
        cardValues[11] = 4;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for(int z = 1; z<=t; z++) {
            init();
            sb.append("#").append(z).append(" ");

            int n = Integer.parseInt(br.readLine());
            int[] pickedCards = new int[n];

            int sum = 0;
            for(int i = 0; i<n; i++) {
                pickedCards[i] = Integer.parseInt(br.readLine());
                cardValues[pickedCards[i]]--;
                sum += pickedCards[i];
            }

            int big = 0;
            int small = 0;
            for(int i = 2; i<=11; i++) {
                if(0 < cardValues[i]) {
                    if(21 <= sum + i) {
                        big++;
                    } else {
                        small++;
                    }
                }
            }

            sb.append(big >= small ? "STOP" : "GAZUA").append("\n");
        }
        System.out.print(sb);
    }

}
