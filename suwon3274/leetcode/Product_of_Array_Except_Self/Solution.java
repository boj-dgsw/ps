class Solution {
    public int[] productExceptSelf(int[] nums) {
        int multiplySum = 1;
        int[] multiplyNums = new int[nums.length];
        List<Integer> zeroList = new ArrayList();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                zeroList.add(i);
                continue;
            }
            multiplySum *= nums[i];
        }

        int size = zeroList.size();
        if (size > 1) {
            for (int i = 0; i < nums.length; i++) {
                multiplyNums[i] = 0;
            }
        } else if (size == 1) {
            for (int i = 0; i < nums.length; i++) {
                if (!zeroList.contains(i)) {
                    multiplyNums[i] = 0;
                } else {
                    multiplyNums[i] = multiplySum;
                }
            }
        } else {
            for (int i = 0; i < nums.length; i++) {
                multiplyNums[i] = multiplySum / nums[i];
            }
        }

        return multiplyNums;
    }
}
