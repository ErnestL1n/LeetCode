/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.814
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
public class Binary_Tree_Pruning {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes){
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
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {1,null,0,0,1};
		System.out.println("We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1 ");
		System.out.println(Arrays.toString(nodes));
		TreeNode root=BuildTree(nodes);

	}

}
