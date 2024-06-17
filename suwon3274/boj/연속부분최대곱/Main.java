package 연속부분최대곱;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        double[] arr = new double[n];
        for(int i = 0; i<n; i++) {
            arr[i] = Double.parseDouble(br.readLine());
        }

        double max = 0;
        for(int i = 0; i<n; i++) {
            double sum = 1;
            for(int j = i; j<n; j++) {
                sum *= arr[j];
                max = Math.max(max, sum);
            }
        }
        System.out.printf("%.3f", max);
    }

}
