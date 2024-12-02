package permutations;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ret = new LinkedList<>();
        backtracking(nums, ret, new ArrayList<>());
        return ret;
    }

    public void backtracking(int[] nums, List<List<Integer>> ret, List<Integer> visit) {
        if (visit.size() == nums.length) {
            ret.add(new ArrayList<>(visit));
            return;
        }

        for (int num : nums) {
            if (visit.contains(num)) continue;

            visit.add(num);
            backtracking(nums, ret, visit);
            visit.remove(visit.size() - 1);
        }
    }
}