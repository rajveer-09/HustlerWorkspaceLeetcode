class Solution {
public:
    pair<ListNode*, ListNode*> reverseList(ListNode* start, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while (k-- && curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return {prev, start};
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        ListNode* prevHead = head;
        dummy->next = head;
        auto curr = head;
        int group = 1;

        while(curr != nullptr){

            int groupSize = 0;
            ListNode* temp = curr;
            
            while (groupSize < group && temp != nullptr) {
                temp = temp->next;
                groupSize++;
            }

            if (groupSize % 2 == 0) {
               
                auto [reversedHead, reversedTail] = reverseList(curr, groupSize);
                prevHead->next = reversedHead;
                reversedTail->next = temp;
                prevHead = reversedTail;
            }

            else {
                for(int i = 0; i < groupSize; i++){
                    prevHead = curr;
                    curr = curr->next;
                }
            }

            curr = temp;
            group++;
        }
        return dummy->next;
    }
};