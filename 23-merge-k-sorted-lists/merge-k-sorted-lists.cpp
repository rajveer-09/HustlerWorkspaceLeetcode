class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the head of each list into the heap
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        // Dummy node to build the result
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            tail->next = node;
            tail = tail->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy->next;
    }
};

/*

<-- BRUTEFORCE -->

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for (ListNode* lst : lists) {
            while (lst) {
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }
        sort(nodes.begin(), nodes.end());

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        for (int node : nodes) {
            cur->next = new ListNode(node);
            cur = cur->next;
        }
        return res->next;
    }
};

<-- BETTER -->

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        for (int i = 1; i < lists.size(); i++) {
            lists[i] = merge(lists[i], lists[i - 1]);
        }
        return lists.back();
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1 != nullptr) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy->next;
    }
};

<-- D&Q (MERGE SORT) -->

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }

private:
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }

        int mid = l + (r - l) / 2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);

        return conquer(left, right);
    }

    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }

        return dummy.next;
    }
};

*/