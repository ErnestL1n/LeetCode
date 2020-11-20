/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.654
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
    TreeNode(int value){this.value=value;}
    TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
    	this.value=value;
    	this.leftchild=leftchild;
    	this.rightchild=rightchild;
    }
}
public class Maximum_Binary_Tree {

	/**
	 * @param args
	 */
	private static int getTreeSize(TreeNode root) {
		if(root==null)return 0;
		return 1+getTreeSize(root.leftchild)+getTreeSize(root.rightchild);
	}
	public static void printTree(TreeNode root) {
		if(root==null)return;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		treenodequeue.offer(root);
		int treesize=getTreeSize(root);
		System.out.println("I am root ,value is "+root.value);
		treesize--;
		while(treesize!=0) {
			TreeNode current=treenodequeue.poll();
			if(current.leftchild!=null) {
				treenodequeue.offer(current.leftchild);
				System.out.println("I am  leftchild  of value "+current.value+" , my value is "+current.leftchild.value);
				treesize--;
			}
			if(current.rightchild!=null) {
				treenodequeue.offer(current.rightchild);
				System.out.println("I am rightchild  of value "+current.value+" , my value is "+current.rightchild.value);
				treesize--;
			}
		}
		
	}
	public static TreeNode constructMaximumBinaryTree(int[] nums) {
		if(nums==null)return null;
		return BuildByIndex(nums,0,nums.length-1);
	}
	private static TreeNode BuildByIndex(int[] nums,int left,int right) {
		if(left>right)return null;
		int maxValue=Integer.MIN_VALUE;
		int maxIndex=-1;
		for(int i=left;i<=right;i++) {
			if(nums[i]>maxValue) {
				maxValue=nums[i];
				maxIndex=i;
			}
		}
		TreeNode root=new TreeNode(maxValue);
		root.leftchild=BuildByIndex(nums,left,maxIndex-1);
		root.rightchild=BuildByIndex(nums,maxIndex+1,right);
		return root;
	}
	public static void main(String[] args) {
		int[] nodes=new int[] {3,2,1,6,0,5};
		System.out.println("Input nodes = \n"+Arrays.toString(nodes));
		System.out.println("\nMaximum Binary Tree is built by input nodes =>");
		printTree(constructMaximumBinaryTree(nodes));

	}

}



// stack implementation
/*
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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        var stk=new Stack<TreeNode>();
        for(var n:nums){
            TreeNode curr=new TreeNode(n);
            while(!stk.empty()&&stk.peek().val<curr.val)
                curr.left=stk.pop();
            if(!stk.empty())
                stk.peek().right=curr;
            stk.push(curr);
        }
        while(stk.size()>1)
            stk.pop();
        return stk.peek();
    }
}
*/














