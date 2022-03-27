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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyOdd = new ListNode();
        ListNode* dummyEven = new ListNode();
        ListNode* odd = dummyOdd;
        ListNode* even = dummyEven;
        while(head!=nullptr){
            odd->next = head;
            odd = odd->next;
            head = head->next;
            if(head!=nullptr){
                even->next = head;
                even = even->next;
                head = head->next;
            }
        }
        even->next = nullptr;
        odd->next = dummyEven->next;
        return dummyOdd->next;
    }
};