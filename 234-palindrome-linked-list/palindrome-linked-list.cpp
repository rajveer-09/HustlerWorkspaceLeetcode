class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

/*

<-- RECURSION -->

class Solution {
    ListNode* cur;

    bool rec(ListNode* node) {
        if (node != nullptr) {
            if (!rec(node->next)) {
                return false;
            }
            if (cur->val != node->val) {
                return false;
            }
            cur = cur->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode* head) {
        cur = head;
        return rec(head);
    }
};


<-- STACK BASED ->

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode* cur = head;

        while (cur != nullptr) {
            stack.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr && cur->val == stack.top()) {
            stack.pop();
            cur = cur->next;
        }

        return cur == nullptr;
    }
};

*/