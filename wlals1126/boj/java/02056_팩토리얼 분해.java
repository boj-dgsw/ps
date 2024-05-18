import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long[] fact = new long[21];
        fact[0] = 1;
        for (int i = 1; i <= 20; i++) {
            fact[i] = fact[i - 1] * i;
        }

        Scanner sc = new Scanner(System.in);
        long num = sc.nextLong();
        sc.close();

        if (num == 0) {
            System.out.println("NO");
            return;
        }

        for (int i = 20; i >= 0; i--) {
            if (num == 0) break;
            if (num >= fact[i]) num -= fact[i];
        }

        if (num == 0) System.out.println("YES");
        else System.out.println("NO");
    }
}
