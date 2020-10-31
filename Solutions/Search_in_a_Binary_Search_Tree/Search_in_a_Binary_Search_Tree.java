/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.700
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(){};
	TreeNode(int value){this.val=value;};
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value;
		this.left=leftchild;
		this.right=rightchild;
	}
}
public class Searchin_a_Binary_Search_Tree {

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
			TreeNode current=treenodequeue.poll();
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			if(leftvalue!=null) {
				TreeNode leftchild=new TreeNode(leftvalue);
				current.left=leftchild;
				treenodequeue.offer(leftchild);
			}
			if(rightvalue!=null) {
				TreeNode rightchild=new TreeNode(rightvalue);
				current.right=rightchild;
				treenodequeue.offer(rightchild);
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
		int treesize=getTreeSize(root);
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		treenodequeue.offer(root);
		System.out.println("I am root , my value is "+root.val);
		treesize--;
		while(treesize!=0){
			TreeNode current=treenodequeue.poll();
			if(current.left!=null) {
				treenodequeue.offer(current.left);
				System.out.println("I am  leftchild of "+current.val+" my value is "+current.left.val);
				treesize--;
			}
			if(current.right!=null) {
				treenodequeue.offer(current.right);
				System.out.println("I am rightchild of "+current.val+" my value is "+current.right.val);
				treesize--;
			}
		}
	}
	public static TreeNode searchBSTRecursive(TreeNode root, int val) {
		if(root==null||root.val==val)return root;
		else if(val<root.val)return searchBSTRecursive(root.left,val);
		else return searchBSTRecursive(root.right,val);
	}
	
    public static TreeNode searchBSTIterative(TreeNode root, int val) {
		while(root!=null) {
			if(root.val==val)return root;
			else if(val<root.val)root=root.left;
			else root=root.right;
		}
		return null;
	}
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {4,2,7,1,3};
		int value=2;
		TreeNode root=BuildTree(nodes);
		System.out.println("Given tree is :");
		printTree(root);
		System.out.println("Given value "+value+" and return the subtree with the root :");
		TreeNode newroot=searchBSTIterative(root,value);
		printTree(newroot);
	}

}
