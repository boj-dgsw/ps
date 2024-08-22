package 그림1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();

        int row = Integer.parseInt(line.split(" ")[0]);
        int column = Integer.parseInt(line.split(" ")[1]);

        int[][] paper = new int[row][column];


        for (int i = 0; i < row; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < column; j++) {
                String s = st.nextToken();
                paper[i][j] = Integer.parseInt(s);
            }
        }

        Queue<Pair> q = new ArrayDeque<>();
        int[][] visit = new int[row][column];
        int picCnt = 0;
        int area;
        int maxArea = 0;
        int[] dRow = new int[]{1, 0, -1, 0};
        int[] dColumn = new int[]{0, 1, 0, -1};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <column; j++) {
                area = 0;
                if (paper[i][j] == 1 && visit[i][j] == 0) {
                    q.add(new Pair(i, j));
                    visit[i][j] = 1;
                    picCnt++;

                    while (!q.isEmpty()) {
                        Pair pair = q.poll();
                        area++;
                        for (int k = 0; k < 4; k++) {
                            int kRow = pair.row + dRow[k];
                            int kColumn = pair.column + dColumn[k];

                            if(kRow < 0 || kRow >= row || kColumn < 0 || kColumn >= column) continue;

                            if(paper[kRow][kColumn] == 1 && visit[kRow][kColumn] == 0) {
                                q.add(new Pair(kRow, kColumn));
                                visit[kRow][kColumn] = 1;
                            }
                        }
                    }

                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }

        System.out.println(picCnt);
        System.out.println(maxArea);
    }

    static class Pair {
        private int row;
        private int column;

        public Pair(int i, int j) {
            row = i;
            column = j;
        }
    }
}
