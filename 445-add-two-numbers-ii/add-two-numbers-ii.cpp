class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        // process until both stacks & carry empty
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top(); s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top(); s2.pop();
            }
            carry = sum / 10;
            // insert at head
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};


/*
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

*/