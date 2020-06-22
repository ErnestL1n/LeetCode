/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.617
class TreeNode{
	int val;
	TreeNode left,right;
	TreeNode(){};
	TreeNode(int value){this.val=value;};
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value; this.left=leftchild; this.right=rightchild;
	}
}
public class Merge_Two_Binary_Trees {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes.length==0||nodes==null)return null;
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
	
	public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
		if(t1==null)return t2==null?null:t2;
		if(t2==null)return t1;
		t1.left=mergeTrees(t1.left,t2.left);
		t1.right=mergeTrees(t1.right,t2.right);
		t1.val+=t2.val;
		return t1;
	}
	public static void main(String[] args) {
		Integer[] tree1=new Integer[] {1,3,2,5};
		Integer[] tree2=new Integer[] {2,1,3,null,4,null,7};
		TreeNode t1=BuildTree(tree1);
		TreeNode t2=BuildTree(tree2);
		System.out.println("T1 is :");
		printTree(t1);
		System.out.println("T2 is :");
		printTree(t2);
		TreeNode MergeTree=mergeTrees(t1,t2);
		
		System.out.println("Merging Two Binary Trees becomes ");
		printTree(MergeTree);
	}
}
