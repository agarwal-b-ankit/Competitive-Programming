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
private:
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==nullptr) return original;
        if(original==target) return cloned;
        TreeNode* child = dfs(original->left, cloned->left, target);
        if(child==nullptr){
            child = dfs(original->right, cloned->right, target);
        }
        return child;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};