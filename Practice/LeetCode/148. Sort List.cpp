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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head=new ListNode();
        ListNode* curr=head;
        while(left!=nullptr && right!=nullptr){
            if(left->val<=right->val){
                curr->next=left;
                curr=curr->next;
                left=left->next;
            } else{
                curr->next=right;
                curr=curr->next;
                right=right->next;
            }
        }
        while(left!=nullptr){
            curr->next=left;
            curr=curr->next;
            left=left->next;
        }
        while(right!=nullptr){
            curr->next=right;
            curr=curr->next;
            right=right->next;
        }
        curr->next=nullptr;
        return head->next;
    }
    
    ListNode* mergeSort(ListNode*head){
        if(head==nullptr) return nullptr;
        else if(head->next==nullptr) return head;
        
        ListNode* slow = head, *fast=head->next;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(curr);
        return merge(left, right);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
        
    }
};