public class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> visited = new HashSet<>();
        ListNode temp = head;

        while (temp != null) {
            if (visited.contains(temp)) {
                return true;
            }
            
            visited.add(temp);
            temp = temp.next;
        }

        return false;
    }
}