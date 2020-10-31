/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1038
//I don't understand the problem is asking for what
//"Revered Inorder Traversal" which is said by https://leetcode.com/lee215/
//Finally, maybe I understand the question's asking for
//Thanks for https://leetcode.com/mmao3/ Iterative one
//Also https://leetcode.com/lee215/ for recursive one
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
public class Binary_Search_Tree_to_Greater_Sum_Tree {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes.length==0||nodes==null)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		TreeNode root=new TreeNode(nodes[0]);
		treenodequeue.offer(root);
		while(!integerqueue.isEmpty()){
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode current=treenodequeue.poll();
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
		int getTreeSize=getTreeSize(root);
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
	static int res=0;
	public static TreeNode bstToGstRecursive(TreeNode root) {
		if(root.right!=null)bstToGstRecursive(root.right);
		res=root.val=root.val+res;
		if(root.left!=null)bstToGstRecursive(root.left);
		return root;
	}
	public static TreeNode bstToGstIterative(TreeNode root) {
		int res2=0;
		Stack<TreeNode> stack=new Stack<>();
		TreeNode current=root;
		while(!stack.isEmpty()||current!=null) {
			while(current!=null) {
				stack.push(current);
				current=current.right;
			}
			current=stack.pop();
			res2=current.val=current.val+res2;
			current=current.left;
		}
		return root;
	}
	public static void main(String[] args) {
		Integer[] nodes1= new Integer[]{4,1,6,0,2,5,7,null,null,null,3,null,null,null,8};
		System.out.println("Original BST Tree1 is  (Reursive version) ");
		TreeNode root1=BuildTree(nodes1);
		printTree(root1);
		System.out.println();
		System.out.println("Original BST to Greater Sum Tree becomes  ");
		bstToGstRecursive(root1);
		printTree(root1);
		Integer[] nodes2= new Integer[]{4,2,6,1,null,null,7};
		System.out.println();
		System.out.println("Original BST Tree2 is (Iterative version) ");
		TreeNode root2=BuildTree(nodes2);
		printTree(root2);
		System.out.println();
		System.out.println("Original BST to Greater Sum Tree becomes  ");
		bstToGstIterative(root2);
		printTree(root2);
	}

}
