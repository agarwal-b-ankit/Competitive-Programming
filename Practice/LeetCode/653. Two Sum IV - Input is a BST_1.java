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
    private boolean searchBST(TreeNode root, int val){
        if(root==null) return false;
        else if(root.val==val) return true;
        else if(root.val>val) return searchBST(root.left,val);
        else return searchBST(root.right,val);
    }
    
    public boolean search(TreeNode curr, TreeNode root, int k) {
        if(curr==null) return false;
        if(2*curr.val!=k && searchBST(root, k-curr.val)) return true;
        return search(curr.left, root, k) || search(curr.right, root, k);
    }
    
	// Time - O(nlogn), Space - O(logn)
    public boolean findTarget(TreeNode root, int k) {
        return search(root, root, k);
    }
}