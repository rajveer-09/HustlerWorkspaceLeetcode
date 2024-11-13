/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* Middle(ListNode* head)
 {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
 }
 ListNode*Reverse(ListNode* head)
 {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while(cur)
    {
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;

 }
    int pairSum(ListNode* head) {
    ListNode* newhead = Middle(head);
    newhead = Reverse(newhead);
    int ans = 0;
    while(newhead && head)
    {
          ans = max(ans,(newhead->val+head->val));
          newhead = newhead->next;
          head = head->next;
    }

        return ans;
    }
};