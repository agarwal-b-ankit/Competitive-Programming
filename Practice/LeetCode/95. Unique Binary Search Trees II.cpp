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
    vector<TreeNode*> generateTrees(int left, int right){
        if(left>right) return vector<TreeNode*>{nullptr};
        vector<TreeNode*> result;
        for(int i=left;i<=right;i++){
            vector<TreeNode*> l = generateTrees(left,i-1);
            vector<TreeNode*> r = generateTrees(i+1,right);
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right=r[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};