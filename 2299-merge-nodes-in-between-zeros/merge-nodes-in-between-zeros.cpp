class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* temp = head->next;
        int sum = 0;

        while(temp != nullptr){
            if(temp->val == 0){
                if(sum != 0){
                    ListNode* newNode = new ListNode(sum);
                    curr->next = newNode;
                    curr = curr->next;
                    sum = 0;
                }
            }
            else{
                sum += temp->val;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};