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
    public int sumEvenGrandparent(TreeNode root) {
        return dfs(root,null,null);
    }
    private int dfs(TreeNode curr,TreeNode parent,TreeNode grandp){
        int res=0;
        if(curr==null)return res;
        if(grandp!=null && grandp.val%2==0)
            res+=curr.val;
        res+=dfs(curr.left,curr,parent);
        res+=dfs(curr.right,curr,parent);
        return res;
    }
}