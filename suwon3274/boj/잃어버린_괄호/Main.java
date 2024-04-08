package 잃어버린_괄호;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String expression = br.readLine();
        StringTokenizer st = new StringTokenizer(expression, "-");
        int[] sums = new int[st.countTokens()];

        for(int i = 0; i<sums.length; i++) {
            StringTokenizer st2 = new StringTokenizer(st.nextToken(), "+");
            sums[i] = Integer.parseInt(st2.nextToken());
            while(st2.hasMoreTokens()) {
                sums[i] += Integer.parseInt(st2.nextToken());
            }
        }

        int result = sums[0];
        for(int i = 1; i<sums.length; i++) {
            result -= sums[i];
        }
        System.out.print(result);
    }

}
