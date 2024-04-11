package 사탕_게임;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        char[][] candies = new char[n][n];

        for(int i = 0; i<n; i++) {
            String s = br.readLine();
            for(int j = 0; j<n; j++) {
                candies[i][j] = s.charAt(j);
            }
        }

        int result = 1;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                char c = candies[i][j];
                if(i - 1 > -1 && c != candies[i - 1][j]) {
                    result = Math.max(result, getLongest(candies, i, j, i - 1, j));
                }
                if(i + 1 < n && c != candies[i + 1][j]) {
                    result = Math.max(result, getLongest(candies, i, j, i + 1, j));
                }
                if(j - 1 > -1 && c != candies[i][j - 1]) {
                    result = Math.max(result, getLongest(candies, i, j, i, j - 1));
                }
                if(j + 1 < n && c != candies[i][j + 1]) {
                    result = Math.max(result, getLongest(candies, i, j, i, j + 1));
                }
            }
        }
        System.out.print(result);
    }

    private static int getLongest(char[][] arr, int x1, int y1, int x2, int y2) {
        char temp = arr[x1][y1];
        arr[x1][y1] = arr[x2][y2];
        arr[x2][y2] = temp;

        int result = 1;
        for(int i = 0; i<n; i++) {
            int size = 1;
            char candy = arr[i][0];
            for(int j = 1; j<n; j++) {
                if(candy == arr[i][j]) {
                    size++;
                    result = Math.max(result, size);
                } else {
                    size = 1;
                    candy = arr[i][j];
                }
            }
        }
        for(int i = 0; i<n; i++) {
            int size = 1;
            char candy = arr[0][i];
            for(int j = 1; j<n; j++) {
                if(candy == arr[j][i]) {
                    size++;
                    result = Math.max(result, size);
                } else {
                    size = 1;
                    candy = arr[j][i];
                }
            }
        }

        char temp2 = arr[x1][y1];
        arr[x1][y1] = arr[x2][y2];
        arr[x2][y2] = temp2;

        return result;
    }

}
