class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Find the middle of the linked list and reverse the first half
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // If the number of nodes is odd, move slow to the next node
        if (fast)
            slow = slow->next;

        // Compare the reversed first half with the second half
        while (prev && slow) {
            if (prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};