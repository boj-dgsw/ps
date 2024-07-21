import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");

        BigDecimal A = new BigDecimal(str[0]);
        BigDecimal B = new BigDecimal(str[1]);
        System.out.println(A.divide(B, 1000, RoundingMode.HALF_UP));
    }
}
