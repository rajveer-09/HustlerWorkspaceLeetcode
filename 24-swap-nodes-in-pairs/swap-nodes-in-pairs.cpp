class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* node = curr->next;
            curr->next = node->next;

            temp->next = node;
            node->next = curr;
            temp = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};