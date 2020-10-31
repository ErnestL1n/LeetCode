/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1325
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){this.value=value;}
	TreeNode(int value,TreeNode leftchild,TreeNode righthchild){
		this.value=value;
		this.leftchild=leftchild;
		this.rightchild=righthchild;
	}
}

public class Delete_Leaves_With_a_Given_Value {
	
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
				TreeNode left=new TreeNode(leftvalue);
				current.leftchild=left;
				treenodequeue.offer(left);
		    	}
			if(rightvalue!=null) {
				TreeNode right=new TreeNode(rightvalue);
				current.rightchild=right;
				treenodequeue.offer(right);
				}
		}
		return root;
	}
	private static int TreeSize(TreeNode root) {
		if(root==null)return 0;
		return 1+TreeSize(root.leftchild)+TreeSize(root.rightchild);
	}
	public static void PrintTree(TreeNode root) {
		if(root==null) {
			System.out.println("I am Empty Tree");
			return;
		}
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		int getTreeSize=TreeSize(root);
		treenodequeue.offer(root);
		System.out.println("I am root ,value is "+root.value);
		getTreeSize--;
		while(getTreeSize!=0) {
			TreeNode current=treenodequeue.poll();
			if(current.leftchild!=null) {
				treenodequeue.offer(current.leftchild);
		    	System.out.println("I am leftchild  of value "+current.value+" , my value is "+current.leftchild.value);
		    	getTreeSize--;
		    	}
			if(current.rightchild!=null) {
				treenodequeue.offer(current.rightchild);
				System.out.println("I am rightchild of value "+current.value+" , my value is "+current.rightchild.value);
				getTreeSize--;
				}
		}
	}
	public static TreeNode removeLeafNodes(TreeNode root, int target) {
		if(root==null)return null;
		if(root.leftchild!=null)root.leftchild=removeLeafNodes(root.leftchild,target);
		if(root.rightchild!=null)root.rightchild=removeLeafNodes(root.rightchild,target);
		return root.leftchild==root.rightchild&&root.value==target?null:root;
	}
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {1,1,1};
		int target=1;
		System.out.println("Initial tree is ");
		TreeNode root=BuildTree(nodes);
		PrintTree(root);
		System.out.println("Delete Leaves With a Given Value,the Tree becomes ");
		PrintTree(removeLeafNodes(root,target));
		
	}

}
