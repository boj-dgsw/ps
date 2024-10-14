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
        List<Integer> list = new ArrayList();
        while(head != null) {
            if(head.val != val) {
                list.add(head.val);
            }
            head = head.next;
        }

        if(list.isEmpty()) {
            return null;
        }

        ListNode ret = new ListNode(list.get(0));
        addNode(list, 1, ret);
        return ret;
    }

    private void addNode(List<Integer> list, int index, ListNode ret) {
        if(list.size() == index) {
            return ;
        }
        ret.next = new ListNode(list.get(index));
        addNode(list, index + 1, ret.next);
    }
}
