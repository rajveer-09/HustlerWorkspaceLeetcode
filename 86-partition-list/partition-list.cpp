class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode* dummy1 = new ListNode(-101);
        ListNode* dummy2 = new ListNode(-101);

        ListNode* temp1 = dummy1;
        ListNode *temp2 = dummy2;

        ListNode* curr = head;

        while(curr){
            if(curr->val < x){
                temp1->next = curr;
                temp1 = temp1->next;
            }else{
                temp2->next = curr;
                temp2 = temp2->next;
            }

            curr = curr->next;
        }

        if(dummy2->next){
            temp1->next = dummy2->next;
            temp2->next = NULL;
        }

        return dummy1->next;

    }
};