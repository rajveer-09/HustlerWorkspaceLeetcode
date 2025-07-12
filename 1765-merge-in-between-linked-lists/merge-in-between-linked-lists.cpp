class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = list1;
        for (int i = 1; i < a; ++i) {
            prevA = prevA->next;
        }

        ListNode* afterB = prevA;
        for (int i = 1; i <= b - a + 1; ++i) {
            ListNode* temp = afterB;
            afterB = afterB->next;
            
            if(i != 1) delete(temp);
        }

        // Connect prevA to list2's head
        prevA->next = list2;

        // Find tail of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // Connect list2's tail to afterB's next
        tail->next = afterB->next;

        return list1;
    }
};
