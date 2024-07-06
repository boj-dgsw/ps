import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        sc.close();
        
        BigInteger n = new BigInteger(input);
        
        BigInteger sqrt = sqrt(n);
        
        System.out.println(sqrt); 
    }
    
    private static BigInteger sqrt(BigInteger n) {
        BigInteger x = n;
        BigInteger y = BigInteger.ZERO;
        
        while (x.compareTo(y) > 0) {
            BigInteger mid = (x.add(y).add(BigInteger.ONE)).shiftRight(1);
            if (mid.multiply(mid).compareTo(n) <= 0) {
                y = mid;
            } else {
                x = mid.subtract(BigInteger.ONE);
            }
        }
        
        return y;
    }
}
