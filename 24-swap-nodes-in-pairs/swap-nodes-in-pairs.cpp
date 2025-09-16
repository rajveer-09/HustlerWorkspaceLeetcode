class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* node = curr->next;
            curr->next = node->next;

            temp->next = node;
            node->next = curr;
            temp = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};

/*

<-- RECURSION -->

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* cur = head;
        ListNode* nxt = head->next;

        cur->next = swapPairs(nxt->next);
        
        nxt->next = cur;

        return nxt;
    }
};

<-- ITERATIVE -->

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy, *curr = head;

        while (curr && curr->next) {
            ListNode* nxtPair = curr->next->next;
            ListNode* second = curr->next;

            // Reverse this pair
            second->next = curr;
            curr->next = nxtPair;
            prev->next = second;

            // Update pointers
            prev = curr;
            curr = nxtPair;
        }

        return dummy.next;
    }
};

<-- USING ARRAY -->

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;

        vector<ListNode*> arr;
        ListNode* cur = head;

        while (cur) {
            arr.push_back(cur);
            cur = cur->next;
        }

        for (size_t i = 0; i + 1 < arr.size(); i += 2) {
            swap(arr[i], arr[i + 1]);
        }

        for (size_t i = 0; i + 1 < arr.size(); i++) {
            arr[i]->next = arr[i + 1];
        }

        arr.back()->next = nullptr;
        return arr[0];
    }
};


*/