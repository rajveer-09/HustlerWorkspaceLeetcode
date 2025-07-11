class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode* start = prev->next;
        ListNode* end = start;
        for (int i = 0; i < right - left; ++i) {
            end = end->next;
        }

        // Detach and reverse the sublist
        ListNode* next = end->next;
        end->next = nullptr;

        prev->next = reverse(start);
        start->next = next;

        return dummy.next;
    }
};
