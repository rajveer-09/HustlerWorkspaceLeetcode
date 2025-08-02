class Solution {
public:
    vector<ListNode*> v;
    Solution(ListNode* head) {
        while(head){
            v.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        int sz = v.size();

        int idx = rand() % sz;
        
        return v[idx]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */