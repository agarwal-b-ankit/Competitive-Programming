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
    private Stack<TreeNode> initLeftStack(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        while(root!=null){
            stack.push(root);
            root = root.left;
        }
        return stack;
    }
    
    private Stack<TreeNode> initRightStack(TreeNode root){
        Stack<TreeNode> stack = new Stack<>();
        while(root!=null){
            stack.push(root);
            root = root.right;
        }
        return stack;
    }
    
    private TreeNode getNextSmallest(Stack<TreeNode> stack){
        if(stack.empty()) return null;
        
        TreeNode curr = stack.pop();
        if(curr.right!=null){
            stack.push(curr.right);
            while(stack.peek().left!=null){
                stack.push(stack.peek().left);
            }
        }
        
        return curr;
    }
    
    private TreeNode getNextLargest(Stack<TreeNode> stack){
        if(stack.empty()) return null;
        
        TreeNode curr = stack.pop();
        if(curr.left!=null){
            stack.push(curr.left);
            while(stack.peek().right!=null){
                stack.push(stack.peek().right);
            }
        }
        
        return curr;
    }
    
	// Time - O(n), Space - O(logn)
    public boolean findTarget(TreeNode root, int k) {
        Stack<TreeNode> leftStack = initLeftStack(root);
        Stack<TreeNode> rightStack = initRightStack(root);
        
        TreeNode small = getNextSmallest(leftStack), large = getNextLargest(rightStack);
        while(small!=null && large!=null && small!=large){
            if(small.val+large.val==k) return true;
            else if(small.val+large.val<k) small = getNextSmallest(leftStack);
            else large = getNextLargest(rightStack);
        }
        return false;
    }
}