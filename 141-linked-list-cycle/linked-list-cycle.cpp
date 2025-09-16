class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};


/*
<-- HASH-SET SOLUTION -->

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> seen;
        ListNode* cur = head;

        while (cur) {
            if (seen.find(cur) != seen.end()) {
                return true;
            }
            seen.insert(cur);
            cur = cur->next;
        }

        return false;
    }
};


*/