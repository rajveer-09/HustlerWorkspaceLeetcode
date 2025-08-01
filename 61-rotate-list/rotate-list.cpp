class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        k %= cnt;
        
        if(k == 0) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i = 0; i < k; i++){
            fast = fast->next;
        }
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* newHead = slow->next;
        
        slow->next = NULL;
        fast->next = head;
        
        return newHead;
    }
};