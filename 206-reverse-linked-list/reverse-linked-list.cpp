class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* newHead = reverseList(head->next);
        
        head->next->next = head;
        
        head->next = NULL;
        
        return newHead;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* current = head;
        
//         while (current != nullptr) {
//             ListNode* nextNode = current->next;
//             current->next = prev;
//             prev = current;
//             current = nextNode;
//         }
        
//         return prev;
//     }
// };


/*

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        
        head->next = nullptr;

        return newHead;
    }
};

*/