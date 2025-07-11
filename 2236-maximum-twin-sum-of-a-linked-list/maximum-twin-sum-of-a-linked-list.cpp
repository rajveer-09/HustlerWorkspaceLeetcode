class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;

        while(head){
            ListNode* nxt = head->next;

            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow= head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    int pairSum(ListNode* head) {

        ListNode* mid = middleNode(head);
        ListNode* second = reverse(mid);

        cout<<"second "<<second->val<<endl;

        int maxi = 0;

        while(second){
            maxi = max(head->val + second->val, maxi);

            head = head->next;
            second = second->next;
        }

        return maxi;
    }
};