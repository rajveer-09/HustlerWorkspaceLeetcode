class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;


        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // har aane waale node ko prev se jodtey jaao....
        // means..prev -> 3 -> 2 -> 4
        // then prev -> 4 -> 3 -> 2
        // jab tak curr yani 2 pr ye operation (r -l) times na ho jaaye

        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            // temp curr ke aage wala node
            curr->next = temp->next;
            // jab temp hatatey to curr ko temp ke aage wale se connect maaro
            
            temp->next = prev->next;
            // temp ke next ko prev ke aage waale se connect maaro bich me lana hai
            prev->next = temp;
            // temp ko prev ke aage laao
        }

        return dummy->next;
    }
};
