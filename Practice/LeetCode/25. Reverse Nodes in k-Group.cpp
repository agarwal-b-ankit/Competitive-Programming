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
private:
    ListNode* reverse(ListNode* head, int k, ListNode*& newHead, ListNode*& newTail){
        ListNode *curr=head,*prev =nullptr,*next;
        for(int i=0;i<k;i++){
            if(curr==nullptr){
                newHead=head;
                newTail=prev;
                return curr;
            }
            prev=curr;
            curr=curr->next;
        }
        curr=head;
        prev=nullptr;
        for(int i=0;i<k;i++){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        newHead=prev;
        newTail=head;
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode *newHead, *newTail;
        ListNode* next = reverse(head,k, newHead, newTail);
        ListNode* nextHead = reverseKGroup(next,k);
        newTail->next=nextHead;
        return newHead;
    }
};