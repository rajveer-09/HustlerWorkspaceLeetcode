/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ans;

        ListNode* temp = head;

        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        for(int i = 0; i < ans.size() / 2; i++){
            if(ans[i] != ans[ans.size() - i - 1]) return false;
        }

        return true;
    }
};