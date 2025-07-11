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

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        ListNode* mid = middleNode(head);
        ListNode* second = reverse(mid);

        cout<<"second "<<second->val<<endl;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(second){
            if(head == second){
                temp->next = second;
                break;
            }
            
            temp->next = head;
            head = head->next;
            temp = temp->next;
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
};