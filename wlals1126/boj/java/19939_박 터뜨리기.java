import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int res = 0;
        
        for (int i = 1; i <= k; i++) {
            res += i;
        }
        
        if (res > n) {
            System.out.println(-1);
        } else {
            if ((n - res) % k == 0) {
                System.out.println(k - 1);
            } else {
                System.out.println(k);
            }
        }
    }
}
