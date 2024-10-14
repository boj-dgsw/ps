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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int num = l1.val + l2.val;
        ListNode ret = new ListNode(num % 10);
        process(ret, l1.next, l2.next, num > 9 ? 1 : 0);
        return ret;
    }

    private void process(ListNode ret, ListNode l1, ListNode l2, int up) {
        if(l1 == null && l2 == null) {
            if(up == 1) {
                ret.next = new ListNode(up);
            }
            return ;
        }

        int num = up;
        if(l1 == null) {
            num += l2.val;
        } else if(l2 == null) {
            num += l1.val;
        } else {
            num += l1.val + l2.val;
        }

        ret.next = new ListNode(num % 10);
        process(ret.next, getNextOrNull(l1), getNextOrNull(l2), num > 9 ? 1 : 0);
    }

    private ListNode getNextOrNull(ListNode node) {
        return node == null ? null : node.next;
    }
}