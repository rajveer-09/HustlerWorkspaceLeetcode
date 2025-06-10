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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p = head;
        ListNode* prev = NULL;
        
        while(p != NULL){
            ListNode* nextNode = p->next;
            p->next = prev;
            prev = p;
            p = nextNode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        // 8 3 13 2 5
        ListNode* p = head->next;
        ListNode* maxNode = head;
        int greater = head->val;
        while(p!= NULL){
            if(p->val >= greater){
                maxNode->next = p;
                maxNode = p;
                greater = p->val;
            }
            p = p->next;
        }
        maxNode->next = NULL;

        return reverseList(head);
    }
};