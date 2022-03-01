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
    TreeNode* build(vector<int>& preorder, int pl, int pr, unordered_map<int,int>& inorderMap, int il, int ir){
        if(pl>pr || il>ir) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int rootPos = inorderMap[root->val];
        root->left = build(preorder, pl+1, pl+rootPos-il, inorderMap, il,rootPos-1);
        root->right = build(preorder, pl+rootPos-il+1, pr, inorderMap, rootPos+1,ir);
        return root;
    }
    
    TreeNode* build1(vector<int>& preorder, int pl, unordered_map<int,int>& inorderMap, int il, int ir){
        if(il>ir) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int rootPos = inorderMap[root->val];
        root->left = build1(preorder, pl+1, inorderMap, il,rootPos-1);
        root->right = build1(preorder, pl+rootPos-il+1, inorderMap, rootPos+1,ir);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++)
            inorderMap[inorder[i]]=i;
        //return build(preorder, 0, preorder.size()-1, inorderMap, 0, inorder.size()-1);
        return build1(preorder, 0, inorderMap, 0, inorder.size()-1);
    }
};