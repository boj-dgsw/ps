package 최소직사각형;

public class Solution {

    public int solution(int[][] sizes) {
        int width = 0, length = 0;

        for(int i = 0; i<sizes.length; i++) {
            if(sizes[i][0] < sizes[i][1]) {
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }

            width = Math.max(width, sizes[i][0]);
            length = Math.max(length, sizes[i][1]);
        }

        return width * length;
    }

}
