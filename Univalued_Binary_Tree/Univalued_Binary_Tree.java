/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.965
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
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

public class Univalued_Binary_Tree {

	/**
	 * @param args
	 */
	
	public static TreeNode BuildTree(Integer[] nodes){
		if(nodes==null||nodes.length==0)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
		TreeNode root=new TreeNode(nodes[0]);
		treenodequeue.offer(root);
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		while(!integerqueue.isEmpty()) {
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode curr=treenodequeue.poll();
			if(leftvalue!=null) {
				TreeNode leftchild=new TreeNode(leftvalue);
				treenodequeue.offer(leftchild);
				curr.left=leftchild;
			}
			if(rightvalue!=null) {
				TreeNode rightchild=new TreeNode(rightvalue);
				treenodequeue.offer(rightchild);
				curr.right=rightchild;
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
		System.out.println("I am root ,my value is "+root.val);
		treesize--;
		while(treesize!=0) {
			TreeNode current=treenodequeue.poll();
			if(current.left!=null) {
				TreeNode leftchild=current.left;
				treenodequeue.offer(leftchild);
				System.out.println("I am  leftchild of "+current.val+"my value is "+leftchild.val);
				treesize--;
			}
			if(current.right!=null) {
				TreeNode rightchild=current.right;
				treenodequeue.offer(rightchild);
				System.out.println("I am rightchild of "+current.val+"my value is "+rightchild.val);
				treesize--;
			}
		}
	}
	
	public static TreeNode mergeTreesRecursive(TreeNode t1, TreeNode t2) {
		if(t1==null)return t2==null?null:t2;
		if(t2==null)return t1;
		t1.left=mergeTreesRecursive(t1.left,t2.left);
		t1.right=mergeTreesRecursive(t1.right,t2.right);
		t1.val+=t2.val;
		return t1;
	}
	
	public static boolean isUnivalTree(TreeNode root) {
        if(root==null)return true;
        if(root.left!=null&&root.left.val!=root.val)return false;
        if(root.right!=null&&root.right.val!=root.val)return false;
        return isUnivalTree(root.left)&&isUnivalTree(root.right);
    }
	
	
	//BFS method thanks to:https://leetcode.com/rock/
	public static boolean isUnivalTreeBFS(TreeNode root) {
        if(root==null)return true;
        if(root.left!=null&&root.left.val!=root.val)return false;
        if(root.right!=null&&root.right.val!=root.val)return false;
        return isUnivalTree(root.left)&&isUnivalTree(root.right);
    }
	
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {2,2,2,5,2};
		System.out.println("A binary tree is univalued if every node in the tree has the same value.");
		TreeNode root=BuildTree(nodes);
		printTree(root);
		System.out.println("Return true if and only if the given tree is univalued.");
		System.out.println("=>"+isUnivalTreeBFS(root));
	}

}
