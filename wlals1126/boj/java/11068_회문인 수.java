import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static boolean isPalindrome(String num) {
        String reversed = new StringBuilder(num).reverse().toString();
        return num.equals(reversed);
    }
    public static String convertBase(int number, int base) {
        StringBuilder result = new StringBuilder();
        while (number > 0) {
            int remainder = number % base;
            char digit = (remainder < 10) ? (char) ('0' + remainder) : (char) ('A' + remainder - 10);
            result.insert(0, digit);
            number /= base;
        }
        return result.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(reader.readLine());

        for (int i = 0; i < T; i++) {
            int number = Integer.parseInt(reader.readLine());

            boolean found = false;
            for (int base = 2; base <= 64; base++) {
                String converted = convertBase(number, base);
                if (isPalindrome(converted)) {
                    found = true;
                    break;
                }
            }

            System.out.println(found ? 1 : 0);
        }
    }
}
