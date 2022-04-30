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
    ListNode* merge2List(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                head->next=list1;
                list1=list1->next;
                head=head->next;
            } else{
                head->next=list2;
                list2=list2->next;
                head=head->next;
            }
        }
        while(list1!=nullptr){
            head->next=list1;
            list1=list1->next;
            head=head->next;
        }
        while(list2!=nullptr){
            head->next=list2;
            list2=list2->next;
            head=head->next;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        if(l>r) return nullptr;
        else if(l==r) return lists[l];
        int mid=(l+r)/2;
        ListNode* list1 = mergeKLists(lists, l, mid);
        ListNode* list2 = mergeKLists(lists, mid+1, r);
        return merge2List(list1, list2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists,0,lists.size()-1);
    }
};