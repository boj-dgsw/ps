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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode ret = new ListNode();
        addNode(ret, list1, list2);
        return ret.next;
    }

    private void addNode(ListNode ret, ListNode list1, ListNode list2) {
        if(list1 == null && list2 == null) {
            return ;
        }

        if(list1 == null || (list2 != null && list2.val <= list1.val)) {
            ret.next = new ListNode(list2.val);
            list2 = list2.next;
        } else if(list2 == null || (list1.val < list2.val)) {
            ret.next = new ListNode(list1.val);
            list1 = list1.next;
        }
        addNode(ret.next, list1, list2);
    }
}
