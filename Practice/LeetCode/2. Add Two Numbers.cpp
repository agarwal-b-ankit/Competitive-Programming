/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode addTwoList(ListNode l1, ListNode l2){
        ListNode l3=null, head=null;
        int carry = 0;
        while(l1!=null && l2!=null){
            if(l3==null){
                l3 = new ListNode();
                head = l3;
            } else{
                l3.next = new ListNode();
                l3 = l3.next;
            }
            l3.val = (l1.val + l2.val + carry)%10;
            carry = (l1.val + l2.val + carry)/10;
            l1=l1.next;
            l2=l2.next;
        }
        while(l1!=null){
            l3.next = new ListNode();
            l3 = l3.next;
            l3.val = (l1.val + carry)%10;
            carry = (l1.val + carry)/10;
            l1=l1.next;
        }
        while(l2!=null){
            l3.next = new ListNode();
            l3 = l3.next;
            l3.val = (l2.val + carry)%10;
            carry = (l2.val + carry)/10;
            l2=l2.next;
        }
        if(carry>0){
            l3.next = new ListNode();
            l3 = l3.next;
            l3.val = carry;
        }
        return head;
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoList(l1,l2);
    }
}