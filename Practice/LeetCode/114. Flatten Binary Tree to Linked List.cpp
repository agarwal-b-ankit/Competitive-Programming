/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* preorderFlat(TreeNode* root){
        TreeNode *tail=root,*left=root->left,*right=root->right;
        root->left=nullptr;
        if(left!=nullptr){
            tail->right=left;
            tail=preorderFlat(left);
        }
        if(right!=nullptr){
            tail->right=right;
            tail=preorderFlat(right);
        }
        return tail;
    }
public:
    void flatten(TreeNode* root) {
        if(root!=nullptr)
            preorderFlat(root);
    }
};