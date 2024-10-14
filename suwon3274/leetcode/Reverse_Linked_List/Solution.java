/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) {
            return head;
        }

        List<Integer> list = new ArrayList();
        while(head != null) {
            list.add(head.val);
            head = head.next;
        }

        ListNode ret = new ListNode(list.get(list.size() - 1));
        addNode(list, list.size() - 2, ret);
        return ret;
    }

    private void addNode(List<Integer> list, int index, ListNode ret) {
        if(index == -1) {
            return ;
        }
        ret.next = new ListNode(list.get(index));
        addNode(list, index - 1, ret.next);
    }
}
