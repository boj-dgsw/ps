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
        List<Integer> list = new ArrayList();
        while(head != null) {
            list.add(head.val);
            head = head.next;
        }

        for(int i = 0; i<list.size(); i++) {
            if(i == list.size() - n) {
                list.remove(i);
            }
        }

        if(list.isEmpty()) {
            return null;
        }

        ListNode ret = new ListNode(list.get(0));
        addNode(list, ret, 1);
        return ret;
    }

    private void addNode(List<Integer> list, ListNode ret, int index) {
        if(list.size() == index) {
            return ;
        }
        ret.next = new ListNode(list.get(index));
        addNode(list, ret.next, index + 1);
    }
}
