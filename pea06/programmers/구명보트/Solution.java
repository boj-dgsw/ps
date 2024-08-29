package 구명보트;

import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int boat = 0;
        int first = 0;
        int last = people.length - 1;
        while (first <= last) {
            if (people[first] + people[last] <= limit) {
                first++;
                last--;
            } else {
                last--;
            }
            boat++;
        }

        return boat;
    }
}