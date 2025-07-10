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

        while(k){
            fast = fast->next;
            k--;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        ListNode* newHead = slow->next;
        slow->next = NULL;

        return newHead;

    }
};