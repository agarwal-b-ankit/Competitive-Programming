/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        queue<Node*> q;
        q.push(root);
        int cnt=1;
        Node* prev = nullptr;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(prev!=nullptr) prev->next=curr;
            prev=curr;
            if(curr->left!=nullptr) q.push(curr->left);
            if(curr->right!=nullptr) q.push(curr->right);
            if(--cnt==0){
                cnt=q.size();
                prev=nullptr;
            }
        }
        return root;
    }
};