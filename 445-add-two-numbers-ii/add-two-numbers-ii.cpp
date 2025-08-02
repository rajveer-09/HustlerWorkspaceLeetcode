class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;

            carry = sum / 10;
        }

        return reverse(dummy->next);

    }
};