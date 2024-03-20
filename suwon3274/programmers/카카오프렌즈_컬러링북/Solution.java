package 카카오프렌즈_컬러링북;

import java.util.Queue;
import java.util.LinkedList;

public class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] visit = new boolean[m][n];
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(picture[i][j] != 0 && !visit[i][j]) {
                    int cnt = 0;
                    numberOfArea++;

                    Queue<Color> que = new LinkedList<>();
                    que.add(new Color(i, j, picture[i][j]));
                    while(!que.isEmpty()) {
                        Color color = que.poll();
                        int x = color.x;
                        int y = color.y;
                        int value = color.value;

                        if(!visit[x][y]) {
                            cnt++;
                            visit[x][y] = true;

                            if(x + 1 < m && picture[x + 1][y] == value) {
                                que.add(new Color(x + 1, y, value));
                            }
                            if(x - 1 > -1 && picture[x - 1][y] == value) {
                                que.add(new Color(x - 1, y, value));
                            }
                            if(y + 1 < n && picture[x][y + 1] == value) {
                                que.add(new Color(x, y + 1, value));
                            }
                            if(y - 1 > -1 && picture[x][y - 1] == value) {
                                que.add(new Color(x, y - 1, value));
                            }
                        }
                    }

                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, cnt);
                }
            }
        }

        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    static class Color {

        int x, y, value;

        Color(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
        }

    }
}