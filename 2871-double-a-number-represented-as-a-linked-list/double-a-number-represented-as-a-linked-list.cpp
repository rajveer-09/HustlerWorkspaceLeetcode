class Solution {
public:
    int dfs(ListNode* node) {
        if (!node) return 0;

        int carry = dfs(node->next);

        int sum = node->val * 2 + carry;
        node->val = sum % 10;

        return sum / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = dfs(head);

        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            head = newHead;
        }
        
        return head;
    }
};


/*
class Solution {
public:
    ListNode* revLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            
            prev = temp;
            temp = nextNode;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* rvs = revLL(head);

        ListNode* curr = rvs;
        int carry = 0;

        while(curr != NULL){
            int sum = carry;

            sum += (curr->val) * 2;
            curr->val = sum % 10;
            carry = sum / 10;

            curr = curr->next;
        }

        head = revLL(rvs);

        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            return newNode;
        }

        return head;
    }
};

*/