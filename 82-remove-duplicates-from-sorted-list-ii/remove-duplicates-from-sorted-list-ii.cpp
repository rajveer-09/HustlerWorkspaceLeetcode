class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-101);
        ListNode* temp = dummy;

        ListNode* curr = head->next;
        ListNode* prev = head;

        if(head->next->val != head->val){
            temp->next = head;
            temp = temp->next;
            // cout<<"...."<<endl;
        }

        while(curr->next != NULL){
            if(curr->val != prev->val && curr->val != curr->next->val){
                // cout<<".."<<endl;
                temp->next = curr;
                temp = temp->next;
            }

            // cout<<"."<<endl;

            prev = curr;
            curr = curr->next;
        }

        if(curr->val != prev->val){
            // cout<<"..."<<endl;
            temp->next = curr;
            temp = temp->next;
        }
        temp->next = NULL;

        return dummy->next;
    }
};