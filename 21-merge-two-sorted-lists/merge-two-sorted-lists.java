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
        ListNode dummy = new ListNode(-1);

        ListNode temp = dummy;

        ListNode curr1 = list1, curr2 = list2;

        while(curr1 != null || curr2 != null){
            if(curr1 != null && curr2 != null){
                if(curr1.val >= curr2.val){
                    temp.next = curr2;
                    curr2 = curr2.next;
                    temp = temp.next;
                }
                else{
                    temp.next = curr1;
                    curr1 = curr1.next;
                    temp = temp.next;
                }
            }
            else if(curr1 != null){
                temp.next = curr1;
                curr1 = curr1.next;
                temp = temp.next;
            }
            else{
                temp.next = curr2;
                curr2 = curr2.next;
                temp = temp.next;
            }
        }


        return dummy.next;
    }
}