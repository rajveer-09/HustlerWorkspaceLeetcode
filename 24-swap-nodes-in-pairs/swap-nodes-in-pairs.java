class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode curr = head;
        ListNode fd = head.next;
        ListNode prev = null;

        while (curr != null && fd != null) {
            ListNode fdd = fd.next;

            if (prev != null) {
                prev.next = fd;
            } 
            else {
                head = fd;
            }

            fd.next = curr;
            curr.next = fdd;

            prev = curr;
            curr = fdd;

            if (curr != null) {
                fd = curr.next;
            }
        }

        return head;
    }
}