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
    int pathSum(TreeNode* root, int target, long pre, unordered_map<int,int>& m){
        if(root==nullptr) return 0;
        pre+=root->val;
        int cnt = m[pre-target];
        m[pre]++;
        cnt+=pathSum(root->left, target, pre, m) + pathSum(root->right,target,pre,m);
        m[pre]--;
        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        unordered_map<int,int> m;
        m[0]=1;
        return pathSum(root, targetSum, 0, m);
    }
};