class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);

        ListNode* prev = dummy; // yaha tak no duplicate
        prev->next = head;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr && curr->val == duplicateVal) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            } else {

                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};