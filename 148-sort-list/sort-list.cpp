class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        ListNode* curr = head;

        while(curr!=nullptr){
            pq.push({curr->val,curr});
            curr = curr->next;
        }

        pair<int ,ListNode*> p = pq.top();
        head = p.second;

        curr = head;
        pq.pop();

        while(!pq.empty()){
            p = pq.top();
            curr->next = p.second;
            
            curr = curr->next;
            pq.pop();
        }

        curr->next = nullptr;
        return head;
    }
};