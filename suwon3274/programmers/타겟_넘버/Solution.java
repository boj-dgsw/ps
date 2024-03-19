package 타겟_넘버;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

    public int solution(int[] numbers, int target) {
        int answer = 0;
        int n = numbers.length;

        Queue<Number> que = new LinkedList<>();
        que.add(new Number(numbers[0], 0));
        que.add(new Number(numbers[0] * -1, 0));

        while(!que.isEmpty()) {
            Number number = que.poll();
            int sum = number.sum;
            int index = number.index;

            if(target == sum && index == n - 1) {
                answer++;
            }

            if(index + 1 < n) {
                que.add(new Number(sum + numbers[index + 1], index + 1));
                que.add(new Number(sum + numbers[index + 1] * -1, index + 1));
            }
        }

        return answer;
    }

    static class Number {

        int sum, index;

        Number(int sum, int index) {
            this.sum = sum;
            this.index = index;
        }

    }

}