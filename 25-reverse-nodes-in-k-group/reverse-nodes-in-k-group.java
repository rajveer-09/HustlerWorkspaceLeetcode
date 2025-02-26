class Solution {
    public ListNode reverseLinkedList(ListNode head) {
        ListNode temp = head;
        ListNode prev = null;

        while (temp != null) {
            ListNode front = temp.next;
            temp.next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    public ListNode getKthNode(ListNode temp, int k) {
        k -= 1;
        while (temp != null && k > 0) {
            k--;
            temp = temp.next;
        }
        return temp;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp = head;
        ListNode prevLast = null;

        while (temp != null) {
            ListNode kThNode = getKthNode(temp, k);
            if (kThNode == null) {
                if (prevLast != null) {
                    prevLast.next = temp;
                }
                break;
            }

            ListNode nextNode = kThNode.next;
            kThNode.next = null;
            reverseLinkedList(temp);

            if (temp == head) {
                head = kThNode;
            } else {
                prevLast.next = kThNode;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }  
}