/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.897
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(){};
	TreeNode(int value){this.val=value;}
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value;
		this.left=leftchild;
		this.right=rightchild;
	}
}

public class Increasing_Order_Search_Tree {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null||nodes.length==0)return null;
		Queue<Integer> integerqueue=new LinkedList<>();
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		TreeNode root=new TreeNode(nodes[0]);
		treenodequeue.offer(root);
		while(!integerqueue.isEmpty()) {
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode current=treenodequeue.poll();
			if(leftvalue!=null) {
				TreeNode leftchild=new TreeNode(leftvalue);
				treenodequeue.offer(leftchild);
				current.left=leftchild;
			}
			if(rightvalue!=null) {
				TreeNode rightchild=new TreeNode(rightvalue);
				treenodequeue.offer(rightchild);
				current.right=rightchild;
			}
		}
		return root;
	}
	
	public static int getTreeSize(TreeNode root) {
		if(root==null)return 0;
		return 1+getTreeSize(root.left)+getTreeSize(root.right);
	}
	
	public static void printTree(TreeNode root) {
		if(root==null)return;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		int treesize=getTreeSize(root);
		treenodequeue.offer(root);
		treesize--;
		System.out.println("I am root , my value is "+root.val);
		while(treesize!=0) {
			TreeNode current=treenodequeue.poll();
			if(current.left!=null) {
				treenodequeue.offer(current.left);
				treesize--;
				System.out.println("I am  leftchild of "+current.val+", my value is "+current.left.val);
			}
			if(current.right!=null) {
				treenodequeue.offer(current.right);
				treesize--;
				System.out.println("I am rightchild of "+current.val+", my value is "+current.right.val);
			}
		}
	}
	
	
	//brilliant solution from:https://leetcode.com/lee215
	public static TreeNode increasingBSTREC(TreeNode root) {
		return increasingBSTREC(root,null);
	}
	
	public static TreeNode increasingBSTREC(TreeNode root,TreeNode tail) {
		if(root==null)return tail;
		TreeNode res=increasingBSTREC(root.left,root);
		root.left=null;
		root.right=increasingBSTREC(root.right,tail);
		return res;
    }
	
	//Iterative solution with stack https://leetcode.com/zzhai/
	public static TreeNode increasingBSTIter(TreeNode root) {
		Stack<TreeNode> stack=new Stack<>();
		//point to the leftmostchild
		TreeNode dummyleftupside=new TreeNode();
		TreeNode dummymove=dummyleftupside;
		while(root!=null||!stack.isEmpty()) {
			if(root!=null) {
				stack.push(root);
				root=root.left;
			}
			else {
				TreeNode current=stack.pop();
				
				//tricky part,check if there is righthchild 
				root=current.right;
				current.left=null;
				dummymove.right=current;
				dummymove=dummymove.right;	
			}
		}
		return dummyleftupside.right;
	}
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {3,1,7,null,2,null,10};
		TreeNode root1=BuildTree(nodes);
		
		System.out.println("Original tree :");
		printTree(root1);
		
		System.out.println("Call Iterative :");
		TreeNode root2=increasingBSTREC(root1);
		printTree(root2);
		
		Integer[] nodes2=new Integer[] {10,3,13,1,7,12,15};
		TreeNode root3=BuildTree(nodes2);
		System.out.println("\n\n");
		System.out.println("Original tree :");
		printTree(root3);
		
		System.out.println("Call Recursive :");
		TreeNode root4=increasingBSTIter(root3);
		printTree(root4);
		
		
		System.out.println("\nBoth are correct :) ");
	}
}
