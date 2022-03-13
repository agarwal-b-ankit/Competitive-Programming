/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int cnt = 0;
    
    public int kthSmallestRecursive(TreeNode root, int k) {
        if(root==null) return -1;
        int val = kthSmallestRecursive(root.left, k);
        if(val!=-1) return val;
        if(++cnt==k) return root.val;
        val = kthSmallestRecursive(root.right, k);
        if(val!=-1) return val;
        return -1;
    }
    
    public int kthSmallestIterative(TreeNode root, int k) {
        Stack<TreeNode> st = new Stack<>();
        while(true){
            while(root!=null){
                st.push(root);
                root = root.left;
            }
            root = st.pop();
            if(--k==0) return root.val;
            root = root.right;
        }
    }
    
    public int kthSmallest(TreeNode root, int k) {
        //return kthSmallestRecursive(root, k);
        return kthSmallestIterative(root, k);
    }
}