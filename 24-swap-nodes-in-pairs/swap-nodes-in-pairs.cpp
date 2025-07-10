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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        ListNode* newHead = head->next;
        ListNode* prev = head;


        while(temp != NULL && temp->next != NULL){
            ListNode* nxt = temp->next->next;
            temp->next->next = temp;
            prev->next = temp->next;

            temp->next = nxt;
            
            prev = temp;
            temp = temp->next;
        }

        return newHead;
    }
};