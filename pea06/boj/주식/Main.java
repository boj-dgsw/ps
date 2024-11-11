package 주식;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            int day = Integer.parseInt(br.readLine());
            int[] arr = new int[day];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < day; j++) {
                arr[j] = Integer.parseInt(st.nextToken());
            }

            int answer = 0;
            int max = arr[day - 1];

            for (int k = day-2; k >= 0; k--) {
                if (arr[k] <= max) {
                    answer += max - arr[k];
                } else {
                    max = arr[k];
                }
            }

            System.out.println(answer);
        }
    }
}
