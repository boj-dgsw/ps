package 자리배정;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int c = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(br.readLine());
        int max = c*r;

        if(k > max) {
            System.out.print(0);
            return ;
        }

        int customer = 1;
        int startX = 1, startY = 1;
        int endX = c, endY = r;

        while(customer < max) {
            for(int i = startY; i<=endY; i++) {
                findSeat(i, startX, customer++, k);
            }
            for(int i = startX + 1; i<=endX; i++) {
                findSeat(endY, i, customer++, k);
            }
            for(int i = endY - 1; i>=startY; i--) {
                findSeat(i, endX, customer++, k);
            }
            for(int i = endX - 1; i>startX; i--) {
                findSeat(startY, i, customer++, k);
            }

            startX++;
            startY++;
            endX--;
            endY--;
        }
    }

    private static void findSeat(int y, int x, int customer, int k) {
        if(k == customer) {
            System.out.print(x + " " + y);
        }
    }

}
