import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        StringBuilder sb = new StringBuilder();
        while ((input = br.readLine()) != null) {
            int N = Integer.valueOf(input);
            int num = 0;
            for (int i = 1;; i++) {
                num = num * 10 + 1;
                num %= N;
                if (num == 0) {
                    sb.append(i).append("\n");
                    break;
                }
            }
        } 
        System.out.println(sb);
    }
}
