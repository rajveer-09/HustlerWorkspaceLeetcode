class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr){
            int val = __gcd(curr->val, prev->val);
            ListNode* node = new ListNode(val);

            node->next = curr;
            prev->next = node;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};