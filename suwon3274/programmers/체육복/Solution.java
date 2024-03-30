package 체육복;

public class Solution {

    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] students = new int[n + 1];

        for(int l : lost) {
            students[l]--;
        }
        for(int r : reserve) {
            students[r]++;
        }

        for(int i = 1; i<=n; i++) {
            if(students[i] == 1) {
                if(i > 1 && -1 == students[i - 1]) {
                    students[i - 1] = 0;
                } else if(i < n && -1 == students[i + 1]) {
                    students[i + 1] = 0;
                }
            }
        }

        for(int i = 1; i<=n; i++) {
            if(students[i] > -1) {
                answer++;
            }
        }

        return answer;
    }

}
