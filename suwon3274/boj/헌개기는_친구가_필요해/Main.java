package 현내기는_친구가_필요해;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static char[][] campus;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        campus = new char[n][m];

        int iX = 0, iY = 0;
        for(int i = 0; i<n; i++) {
            String s = br.readLine();
            for(int j = 0; j<m; j++) {
                campus[i][j] = s.charAt(j);
                if('I' == campus[i][j]) {
                    iX = i;
                    iY = j;
                }
            }
        }

        Queue<Square> que = new LinkedList<>();
        que.add(new Square(iX, iY));

        int result = 0;
        boolean[][] visit = new boolean[n][m];
        while(!que.isEmpty()) {
            Square square = que.poll();
            int x = square.x;
            int y = square.y;

            if(!visit[x][y]) {
                visit[x][y] = true;

                if('P' == campus[x][y]) {
                    result++;
                }

                if(x + 1 < n && 'X' != campus[x + 1][y]) {
                    que.add(new Square(x + 1, y));
                }
                if(x - 1 > -1 && 'X' != campus[x - 1][y]) {
                    que.add(new Square(x - 1, y));
                }
                if(y + 1 < m && 'X' != campus[x][y + 1]) {
                    que.add(new Square(x, y + 1));
                }
                if(y - 1 > -1 && 'X' != campus[x][y - 1]) {
                    que.add(new Square(x, y - 1));
                }
            }
        }
        System.out.print(result == 0 ? "TT" : result);
    }

    static class Square {

        int x, y;

        Square(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

}
