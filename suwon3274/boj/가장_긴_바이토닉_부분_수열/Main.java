package 가장_긴_바이토닉_부분_수열;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        int[] dpASC = new int[n];
        int[] dpDESC = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        dpASC[0] = 1;
        for(int i = 1; i<n; i++) {
            int max = 0;
            for(int j = i - 1; j>-1; j--) {
                if(arr[i] > arr[j]) {
                    max = Math.max(max, dpASC[j]);
                }
            }
            dpASC[i] = max + 1;
        }
        dpDESC[n - 1] = 1;
        for(int i = n - 2; i>-1; i--) {
            int max = 0;
            for(int j = i + 1; j<n; j++) {
                if(arr[i] > arr[j]) {
                    max = Math.max(max, dpDESC[j]);
                }
            }
            dpDESC[i] = max + 1;
        }

        int max = 0;
        for(int i = 0; i<n; i++) {
            max = Math.max(max, dpASC[i] + dpDESC[i] - 1);
        }
        System.out.print(max);
    }

}
