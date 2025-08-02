class Solution {
public:
    ListNode* merge(ListNode* L1, ListNode* L2) {
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (L1 && L2) {
            if (L1->val <= L2->val) {
                temp->next = L1;
                L1 = L1->next;
            } else {
                temp->next = L2;
                L2 = L2->next;
            }
            temp = temp->next;
        }

        temp->next = L1 ? L1 : L2;
        return dummy.next;
    }

    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = middle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        ListNode* L1 = mergeSort(head);
        ListNode* L2 = mergeSort(rightHead);

        return merge(L1, L2);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};