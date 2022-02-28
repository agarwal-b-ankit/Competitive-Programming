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
    
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;
        int cnt=0;
        while(curr!=null){
            cnt++;
            curr = curr.next;
        }
        curr = head;
        if(cnt==n) return head.next;
        for(int i=0;i<cnt-n-1;i++) curr=curr.next;
        curr.next=curr.next.next;
        return head;
    }
}