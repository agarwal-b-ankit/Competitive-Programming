/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** lca) {
        if(root==nullptr) return false;
        bool left =  lowestCommonAncestor(root->left, p, q, lca);
        bool right = lowestCommonAncestor(root->right, p, q, lca);
        if(left && right && *lca==nullptr){
            *lca = root;
        }
        if((left || right) && (root==p || root == q)){
            *lca = root;
        }
        if(root == p || root == q || left || right) return true;
        else return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = nullptr;
        TreeNode** lca = &node;
        lowestCommonAncestor(root, p, q, lca);
        return *lca;
    }
};