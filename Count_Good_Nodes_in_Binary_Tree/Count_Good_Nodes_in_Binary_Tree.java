/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1448
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){this.value=value;};
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.value=value;
		this.leftchild=leftchild;
		this.rightchild=rightchild;
	}
}
public class Count_Good_Nodes_in_Binary_Tree {

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
		System.out.println("I am root ,value is "+root.value);
		while(!integerqueue.isEmpty()) {
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode current=treenodequeue.poll();
			if(leftvalue!=null) {
				TreeNode left=new TreeNode(leftvalue);
				current.leftchild=left;
				treenodequeue.offer(left);
				System.out.println("I am  leftchild  of value "+current.value+" , my value is "+current.leftchild.value);
			}
			if(rightvalue!=null) {
				TreeNode right=new TreeNode(rightvalue);
				current.rightchild=right;
				treenodequeue.offer(right);
				System.out.println("I am rightchild  of value "+current.value+" , my value is "+current.rightchild.value);
			}
		}
		return root;
	}
	private static int goodnodes=0;
	public static int GoodNodes(TreeNode root) {
		if(root==null)return 0;
		CountGoodNodes(root,Integer.MIN_VALUE);
		return goodnodes;
	}
	private static void CountGoodNodes(TreeNode root,int max) {
		if(root==null)return;
		if(root.value>=max)goodnodes++;
		max=Math.max(max, root.value);
		CountGoodNodes(root.leftchild,max);
		CountGoodNodes(root.rightchild,max);
	}
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {3,1,4,3,null,1,5};
		System.out.println("Input nodes = "+Arrays.toString(nodes)+"\n");
		System.out.print("\n There are "+GoodNodes(BuildTree(nodes))+" GoodNodes");

	}

}
