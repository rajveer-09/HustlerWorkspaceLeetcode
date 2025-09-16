
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode* cur = head;

        while (cur) {
            if (seen.find(cur) != seen.end()) {
                return cur;
            }
            seen.insert(cur);
            cur = cur->next;
        }

        return NULL;
    }
};
