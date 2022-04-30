/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "*";
        return to_string(root->val) + "|" + serialize(root->left)+ "|" +serialize(root->right);
    }
    
    TreeNode* deserialize(string& data, int& ind) {
        if(data[ind]=='*'){
            ind+=2;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode();
        
        int i;
        for(i=ind;i<data.length();i++) if(data[i]=='|') break;
        stringstream st(data.substr(ind,i-ind));
        st>>root->val;
        ind=i+1;
        
        root->left = deserialize(data,ind);
        root->right = deserialize(data,ind);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind=0;
        return deserialize(data,ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));