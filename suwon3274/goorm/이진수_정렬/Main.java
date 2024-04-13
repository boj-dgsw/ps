import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        List<Num> list = new ArrayList<>();

        StringTokenizer st2 = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            int origin = Integer.parseInt(st2.nextToken());
            int cnt = calculate(origin);
            list.add(new Num(origin, cnt));
        }

        list.sort((n1, n2) -> {
            if (n2.cnt == n1.cnt) {
                return n2.origin - n1.origin;
            }
            return n2.cnt - n1.cnt;
        });
        System.out.print(list.get(k - 1).origin);
    }

    private static int calculate(int number) {
        int cnt = 0;
        while(number != 0) {
            if(number % 2 == 1) {
                cnt++;
            }
            number /= 2;
        }
        return cnt;
    }

    static class Num {

        int origin, cnt;

        Num(int origin, int cnt) {
            this.origin = origin;
            this.cnt = cnt;
        }

    }
}
