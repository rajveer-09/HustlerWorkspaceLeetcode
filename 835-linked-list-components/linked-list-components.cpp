class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int count = 0;

        while (head) {
            if (st.count(head->val) && 
               (!head->next || !st.count(head->next->val))) {
                // ya toh head ka next na ho ... agr hoto list me na ho..tb cnt++ krnge
                count++;
            }

            head = head->next;
        }

        return count;
    }
};
