/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode ret = new ListNode(0, head);
        process(ret, head, val);
        return ret.next;
    }

    private void process(ListNode ret, ListNode head, int val) {
        //termination check
        if(head == null) {
            ret.next = null;//last node's next must be null
            return ;
        }

        //recursion
        if(val == head.val) {
            if(null == head.next) {
                process(ret, null, val);
            } else if(val == head.next.val) {
                process(ret, head.next, val);
            } else {
                ret.next = head.next;
                process(ret.next, head.next.next, val);
            }
        } else {
            ret.next = head;
            process(ret.next, head.next, val);
        }
    }
}