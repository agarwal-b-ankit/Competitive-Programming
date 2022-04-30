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
public:
    void maxPathSum(TreeNode* root, int& sum1, int& sum2) {
        int lsum1=-2000,lsum2=-2000,rsum1=-2000,rsum2=-2000;
        if(root==nullptr) return;
        maxPathSum(root->left, lsum1, lsum2);
        maxPathSum(root->right, rsum1, rsum2);
        sum1=max(root->val, max(root->val+lsum1, root->val+rsum1));
        sum2=max(max(lsum2,rsum2),max(sum1,root->val+lsum1+rsum1));
    }
    
    int maxPathSum(TreeNode* root) {
        int sum1,sum2;
        maxPathSum(root, sum1,sum2);
        return sum2;
    }
};