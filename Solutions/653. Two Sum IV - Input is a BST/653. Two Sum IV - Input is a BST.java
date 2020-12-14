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
 
 //set implementation
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        var s=new HashSet<Integer>();
        return dfs(root,s,k);
    }
    public boolean dfs(TreeNode root,HashSet<Integer> s,int k){
        if(root==null)
            return false;
        if(s.contains(k-root.val))
            return true;
        s.add(root.val);
        return dfs(root.left,s,k) || dfs(root.right,s,k);
    }
}


//binary search method

class Solution {
    private TreeNode root;
    public boolean findTarget(TreeNode node, int k) {
        if(this.root==null)
            this.root=node;
        if(node==null)
            return false;
        if(search(node,k-node.val))
            return true;
        return findTarget(node.left,k) || findTarget(node.right,k);
    }
    private boolean search(TreeNode node,int complement){
        TreeNode curr=this.root;
        while(curr!=null){
            if(curr.val>complement)
                curr=curr.left;
            else if(curr.val<complement)
                curr=curr.right;
            else return curr==node?false:true;
        }
        return false;
    }
}