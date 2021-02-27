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
    public TreeNode invertTree(TreeNode root) {
        if(root!=null){
            TreeNode temp=root.left;
            root.left=invertTree(root.right);
            root.right=invertTree(temp);
        }
        return root;
    }
}

class Solution {
    public TreeNode invertTree(TreeNode root) {
        Stack<TreeNode> stk=new Stack<>();
        stk.push(root);
        while(!stk.isEmpty()){
            var tmp=stk.pop();
            if(tmp!=null){
                stk.push(tmp.left);
                stk.push(tmp.right);
                TreeNode t=tmp.left;
                tmp.left=tmp.right;
                tmp.right=t;
            }
        }
        return root;
    }
}