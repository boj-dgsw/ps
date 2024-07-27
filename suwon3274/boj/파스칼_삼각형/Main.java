package 파스칼_삼각형;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int height = r + w - 1;

        int[][] pascal = new int[r + w][];
        for(int i = 1; i<=height; i++) {
            pascal[i] = new int[i + 1];
        }

        pascal[1][1] = 1;
        for(int i = 2; i<=height; i++) {
            for(int j = 1; j<=i; j++) {
                if(j == 1 || j == i) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }

        int result = 0;
        for(int i = r, end = c; i<=height; i++, end++) {
            for(int j = c; j<=end; j++) {
                result += pascal[i][j];
            }
        }
        System.out.print(result);
    }

}
