package 예산;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] provinces = new int[n];

        for(int i = 0; i<n; i++) {
            provinces[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(provinces);

        int m = Integer.parseInt(br.readLine());

        int answer = -1;
        int l = 1, r = provinces[n - 1];
        while(l<=r) {
            int mid = (l + r) / 2;
            int sum = 0;
            for(int i = 0; i<n; i++) {
                sum += Math.min(mid, provinces[i]);
            }

            if(sum <= m) {
                answer = Math.max(answer, Math.min(mid, provinces[n - 1]));
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        System.out.print(answer);
    }

}
