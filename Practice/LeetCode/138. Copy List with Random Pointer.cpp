/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solveUsingMap(Node* head){
        unordered_map<Node*, Node*> m;
        Node* curr = head;
        while(curr){
            Node* node = new Node(curr->val);
            m[curr]=node;
            curr=curr->next;
        }
        curr = head;
        while(curr){
            if(curr->next) m[curr]->next=m[curr->next];
            if(curr->random) m[curr]->random=m[curr->random];
            curr=curr->next;
        }
        return m[head];
    }
    
    Node* solveWithoutMap(Node* head){
        if(head==NULL) return head;
        Node* curr = head;
        // insert new nodes in between existing nodes (a -> b should now look like a -> a' -> b -> b')
        while(curr){
            Node* node = new Node(curr->val);
            node->next=curr->next;
            curr->next=node;
            curr=node->next;
        }
        // update the random pointer for the new nodes to point to corresponding new nodes
        curr=head;
        while(curr){
            if(curr->random) 
                curr->next->random = curr->random->next;
            curr=curr->next->next;
        }
        // detach original nodes from the list, thus, forming the original and new link lists
        Node* newHead = head->next;
        curr=head;
        while(curr){
            Node* newCurr = curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            if(newCurr->next)
                newCurr->next = newCurr->next->next;
        }
        return newHead;
    }
    
    Node* copyRandomList(Node* head) {
        //return solveUsingMap(head);
        return solveWithoutMap(head);
    }
};