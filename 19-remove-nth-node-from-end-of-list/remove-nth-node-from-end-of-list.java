class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        int ttl = 0;

        while (temp != null) {
            ttl++;
            temp = temp.next;
        }

        if (n == ttl) return head.next;

        int cnt = 0;
        temp = head;

        while (cnt < ttl - n - 1) {
            temp = temp.next;
            cnt++;
        }

        temp.next = temp.next.next;

        return head;
    }
}