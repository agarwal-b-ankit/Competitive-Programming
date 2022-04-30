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
bool compare(ListNode* l1, ListNode* l2){
    return l1->val>l2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&compare)> pq(compare);
        for(ListNode* list:lists)
            if(list!=nullptr)
                pq.push(list);
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            head->next = curr;
            head=head->next;
            if(curr->next!=nullptr) pq.push(curr->next);
        }
        return dummy->next;
    }
};