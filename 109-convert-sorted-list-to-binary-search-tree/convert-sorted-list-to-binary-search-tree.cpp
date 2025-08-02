class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode* slow = head, *prev = NULL, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = NULL;
        ListNode* mid = slow;
        // [.......][X.......]
        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};