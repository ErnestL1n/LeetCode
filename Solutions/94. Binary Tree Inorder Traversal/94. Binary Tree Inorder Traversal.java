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
 //recursive
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        var res=new ArrayList<Integer>();
        inorder(root,res);
        return res;
    }
    public void inorder(TreeNode root,List<Integer> res){
        if(root!=null){
            inorder(root.left,res);
            res.add(root.val);
            inorder(root.right,res);
        }
    }
}


// iteration stack

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        var stk=new Stack<TreeNode>();
        var res=new ArrayList<Integer>();
        while(!stk.empty()||root!=null){
            while(root!=null){
                stk.push(root);
                root=root.left;
            }
            root=stk.pop();
            res.add(root.val);
            root=root.right;
        }
        return res;
    }
}