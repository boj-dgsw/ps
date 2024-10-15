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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nodeForCnt = head;
        int size = 0;
        while(nodeForCnt != null) {
            size++;
            nodeForCnt = nodeForCnt.next;
        }

        if(size == n) {
            return head.next;
        }
        ListNode pre = head;
        head = head.next;
        size--;

        removeNthNodeFromList(pre, head, size, n);
        return pre;
    }

    private void removeNthNodeFromList(ListNode pre, ListNode head, int size, int n) {
        while(head != null) {
            if(size == n) {
                pre.next = head.next;
                pre = head.next;
                if(head.next == null) {
                    head = null;
                } else {
                    head = head.next.next;
                }
                size -= 2;
            } else {
                pre.next = head;
                pre = head;
                head = head.next;
                size -= 1;
            }
        }
    }
}
