class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1) current->next = list1;
        if (list2) current->next = list2;

        return dummy->next;
    }
};

/*
<-- RECURSION -->

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } 
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

<-- BRUTE FORCE -->

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL){
            arr.push_back(temp1->val); 
            temp1 = temp1->next; 
        }

        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2 = temp2->next; 
        }

        sort(arr.begin(), arr.end());

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for(int i = 0; i < arr.size(); i++){
            temp->next = new ListNode(arr[i]); 
            temp = temp->next; 
        }

        return dummyNode->next; 
    }
};



*/