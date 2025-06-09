class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(), nums.end());

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* temp = head;

        while(temp != nullptr){
            if(!set.count(temp->val)){
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }

        curr->next = nullptr;
        
        return dummy->next;
    }
};
