class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode oddDummy = new ListNode(0);
        ListNode evenDummy = new ListNode(0);

        ListNode odd = oddDummy, even = evenDummy;
        ListNode current = head;
        int index = 1;

        while (current != null) {
            if (index % 2 == 1) {
                odd.next = current;
                odd = odd.next;
            } 
            else {
                even.next = current;
                even = even.next;
            }
            current = current.next;
            index++;
        }

        even.next = null;
        odd.next = evenDummy.next;

        return oddDummy.next;
    }
}