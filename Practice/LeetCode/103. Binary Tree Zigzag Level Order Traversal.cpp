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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int cnt=q.size();
            vector<int> temp;
            while(cnt--){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            if(flag) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag^=true;
        }
        return ans;
    }
};