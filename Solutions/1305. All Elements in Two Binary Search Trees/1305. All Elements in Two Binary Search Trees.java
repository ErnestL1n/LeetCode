/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1305
import java.util.*;
class TreeNode{
    int val;
    TreeNode left,right;
    TreeNode(){};
    TreeNode(int value){
        this.val=value;
    }
    TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
        this.val=value;
        this.left=leftchild;
        this.right=rightchild;
    }
}
class All_Elements_in_Two_Binary_Search_Trees{
    public static List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        var res=new ArrayList<Integer>();
        inorder(root1,res);
        inorder(root2,res);
        Collections.sort(res);
        return res;
    }
    private static void inorder(TreeNode root,List<Integer> ans){
        if(root==null)
        return;
        inorder(root.left,ans);
        ans.add(root.val);
        inorder(root.right,ans);
    }
    public static TreeNode BuildTree(Integer[] nodes){
        if(nodes==null||nodes.length==0)
        return null;
        Queue<Integer> integerqueue=new LinkedList<>();
        Queue<TreeNode> treenodequeue=new LinkedList<>();
        for(int i=1;i<nodes.length;++i)
        integerqueue.offer(nodes[i]);
        TreeNode root=new TreeNode(nodes[0]);
        treenodequeue.offer(root);
        while(!integerqueue.isEmpty()){
            TreeNode curr=treenodequeue.poll();
            Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
            Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
            if(leftvalue!=null){
                TreeNode leftchild=new TreeNode(leftvalue);
                curr.left=leftchild;
                treenodequeue.offer(leftchild);
            }
            if(rightvalue!=null){
                TreeNode rightchild=new TreeNode(rightvalue);
                curr.right=rightchild;
                treenodequeue.offer(rightchild);
            }
        }
        return root;
    }
    public static int TreeSize(TreeNode root){
        if(root==null)
        return 0;
        return 1+TreeSize(root.left)+TreeSize(root.right);
    }

	public static void PrintTree(TreeNode root) {
		if(root==null)return;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		int getTreeSize=TreeSize(root);
		treenodequeue.offer(root);
		System.out.println("I am root ,value is "+root.val);
		getTreeSize--;
		while(getTreeSize!=0) {
			TreeNode current=treenodequeue.poll();
			if(current.left!=null) {
				treenodequeue.offer(current.left);
				System.out.println("I am leftchild  of value "+current.val+" , my value is "+current.left.val);
				getTreeSize--;
			}
			if(current.right!=null) {
				treenodequeue.offer(current.right);
				System.out.println("I am rightchild of value "+current.val+" , my value is "+current.right.val);
				getTreeSize--;
			}
		}
		
	}

    public static void main(String[] args){
        Integer[] nodes1=new Integer[] {2,1,4};
		TreeNode root1=BuildTree(nodes1);
        PrintTree(root1);
        Integer[] nodes2=new Integer[] {1,0,3};
		TreeNode root2=BuildTree(nodes2);
		PrintTree(root2);
		System.out.println("Return a list containing all the integers from both trees sorted in ascending order"+getAllElements(root1,root2));
    }
}











//update add new implementation,credit to https://leetcode.com/votrubac/
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
 
class Solution {
    private void pushleft(Stack<TreeNode> s,TreeNode root){
        while(root!=null){
            s.push(root);
            root=root.left;
        }
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        var res=new ArrayList<Integer>();
        var s1=new Stack<TreeNode>();
        var s2=new Stack<TreeNode>();
        pushleft(s1,root1);
        pushleft(s2,root2);
        while(!s1.empty()||!s2.empty()){
            var s=s1.empty()?s2:s2.empty()?s1:s1.peek().val<s2.peek().val?s1:s2;
            var n=s.pop();
            res.add(n.val);
            pushleft(s,n.right);
        }
        return res;
    }
}
*/















