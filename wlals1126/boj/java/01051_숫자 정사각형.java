import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int row, col;
    static int[][] rectangle;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());
        rectangle = new int[row][col];

        for (int i = 0; i < row; i++) {
            String input = br.readLine();
            for (int j = 0; j < col; j++) {
                rectangle[i][j] = input.charAt(j) - '0';
            }
        }

        int maxSize = 1; 
        int minDimension = Math.min(row, col); 

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                maxSize = Math.max(maxSize, findLargestSquare(i, j, minDimension));
            }
        }

        System.out.println(maxSize);
    }

    public static int findLargestSquare(int x, int y, int maxSize) {
        int largestSquareSize = 1;
        for (int len = 1; len < maxSize; len++) {
            if (x + len < row && y + len < col) {
                if (rectangle[x][y] == rectangle[x][y + len] &&
                        rectangle[x][y] == rectangle[x + len][y] &&
                        rectangle[x][y] == rectangle[x + len][y + len]) {
                    largestSquareSize = (len + 1) * (len + 1);
                }
            }
        }
        return largestSquareSize;
    }
}
