package 숫자_정사각형;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        for(int i = 0; i<n; i++) {
            String s = br.readLine();
            for(int j = 0; j<m; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        for(int size = Math.min(n, m); size>0; size--) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<m; j++) {
                    int number = arr[i][j];
                    if(i + size - 1 < n && arr[i + size - 1][j] == number) {
                        if(j + size - 1 < m && arr[i][j + size - 1] == number) {
                            if(arr[i + size - 1][j + size - 1] == number) {
                                System.out.print(size * size);
                                return ;
                            }
                        }
                    }
                }
            }
        }
    }

}
