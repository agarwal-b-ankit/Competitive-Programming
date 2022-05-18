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
    vector<int> directionToTake;
    bool dfs(TreeNode* root, TreeNode* target, vector<int>& direction){
        if(root==nullptr) return false;
        if(root==target){
            directionToTake = direction;
            return true;
        }
        direction.push_back(-1);
        if(dfs(root->left, target, direction)) return true;
        direction.pop_back();
        direction.push_back(1);
        if(dfs(root->right, target, direction)) return true;
        direction.pop_back();
        return false;
    }
    
    TreeNode* findNode(TreeNode*root, int ind){
        if(ind==directionToTake.size()) return root;
        if(directionToTake[ind]==-1) return findNode(root->left, ind+1);
        else return findNode(root->right, ind+1);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<int> temp;
        dfs(original, target, temp);
        return findNode(cloned, 0);
    }
};