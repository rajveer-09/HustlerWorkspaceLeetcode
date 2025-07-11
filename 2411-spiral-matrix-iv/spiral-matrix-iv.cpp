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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m, vector<int>(n, -1));

        ListNode* temp = head;

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        int cnt = 1;

        while(top <= bottom && left <= right && temp != NULL) {
            for(int i = left; i <= right; i++){
                if(!temp) break;
                ans[top][i] = temp->val;
                temp = temp->next;
            }
            top++;
            if(!temp) break;

            for(int i = top; i <= bottom; i++){
                if(!temp) break;
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;
            if(!temp) break;

            if(top <= bottom) {
                for(int i = right; i >= left; i--){
                    if(!temp) break;
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }
            if(!temp) break;

            if(left <= right) {
                for(int i = bottom; i >= top; i--){
                    if(!temp) break;
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
            if(!temp) break;
        }

        return ans;
    }
};