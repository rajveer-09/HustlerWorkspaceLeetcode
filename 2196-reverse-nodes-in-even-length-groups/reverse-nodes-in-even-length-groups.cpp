class Solution {
public:
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* current = start;
        ListNode* groupEnd = end->next;
        
        while (current != groupEnd) {
            ListNode* nextNode = current->next;
            current->next = prev;

            prev = current;
            current = nextNode;
        }
        
        start->next = groupEnd;
        return prev;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;
        ListNode* current = head;

        int groupLen = 1;
        
        while (current) {
            ListNode* groupStart = current;
            ListNode* groupEnd = current;

            int actualLen = 1;
            
            while (actualLen < groupLen && groupEnd->next) {
                groupEnd = groupEnd->next;
                actualLen++;
            }
            
            ListNode* nextGroupStart = groupEnd->next;
            
            if (actualLen % 2 == 0) {
                ListNode* reversedStart = reverseList(groupStart, groupEnd);
                prevGroupEnd->next = reversedStart;
                prevGroupEnd = groupStart;

            } 
            else {
                prevGroupEnd = groupEnd;
            }
            
            current = nextGroupStart;
            groupLen++;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};