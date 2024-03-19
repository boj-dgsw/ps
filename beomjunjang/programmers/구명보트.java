import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer=0;
        int start=0,end=people.length-1;
        Arrays.sort(people);
        while(start < end){
            int sumWeight=people[start]+people[end];
            if(sumWeight <= limit){
                start++;
            }
            end--;
            answer++;
        }
        if(end==start) answer++;
        return answer;
    }
}
