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
    private long totalsum=0,res=0;
    public int maxProduct(TreeNode root) {
        totalsum=dfs(root);
        dfs(root);
        return (int)(res%(1e9 + 7));
    }
    int dfs(TreeNode root){
        if(root==null)
            return 0;
        int cursum=dfs(root.left)+dfs(root.right)+root.val;
        res=Math.max(res,cursum*(totalsum-cursum));
        return cursum;
    }
}