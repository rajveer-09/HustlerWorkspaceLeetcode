class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        int width = n / k;
        int remainder = n % k;   // how many parts get 1 extra node

        vector<ListNode*> result;
        ListNode* curr = head;

        for (int i = 0; i < k; ++i) {
            ListNode* partHead = curr;
            int partSize = width + (i < remainder ? 1 : 0); // add extra if needed

            for (int j = 1; j < partSize && curr; ++j) {
                curr = curr->next;
            }

            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;  // cut off current part
                curr = nextPart;
            }

            result.push_back(partHead);
        }

        return result;
    }
};
