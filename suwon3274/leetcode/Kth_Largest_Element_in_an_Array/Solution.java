class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> que = new PriorityQueue(Collections.reverseOrder());
        for(int i = 0; i<nums.length; i++) {
            que.add(nums[i]);
        }
        for(int i = 1; i<k; i++) {
            que.poll();
        }
        return que.peek();
    }
}
