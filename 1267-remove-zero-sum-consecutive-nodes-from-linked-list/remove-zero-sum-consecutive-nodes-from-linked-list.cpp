class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // jab v head deletion possible ho dummy node jarur bnao..
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> prefixMap;
        int prefixSum = 0;

        ListNode* curr = dummy;

        while (curr) {
            prefixSum += curr->val;

            prefixMap[prefixSum] = curr;

            curr = curr->next;
        }

        prefixSum = 0;
        curr = dummy;

        while (curr) {
            prefixSum += curr->val;

            curr->next = prefixMap[prefixSum]->next;

            curr = curr->next;
        }

        return dummy->next;
    }
};

/*
-> if the same prefix sum appears again later, that means the sum of the nodes in between is zero.
That’s the key trick.
-> [0...x......Y......x.....]
->      |_____________|
in dono points pr values same hogyi means...inke bich me jo elements jude unka koi meaning nhi tha....they were sum upto zero.

e.g = [1,2,3,-3,-2]
==> [1, 3, 6, 3, 1]
        |_________|
-> do points ke range ke sabhi values ke add krne ka no benefits .. they are summing ot zero

e.g [1,2,3,-3,-2, 5, 3, 4, 1, -1, -4, 3]
==> [1,3,6, 3,  1, 6, 9, 13, 14, 13, 9, 12]
       |________|        |____________|

    ->[1, 5, 3, 3] 
*/