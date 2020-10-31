/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.938
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){this.value=value;};
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.leftchild=leftchild;
		this.rightchild=rightchild;
		this.value=value;
	}
	
}
public class Range_Sum_of_BST {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null||nodes.length==0)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
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
				System.out.println("I am leftchild  of value "+current.value+" , my value is "+left.value);
			}
			if(rightvalue!=null) {
				TreeNode right=new TreeNode(rightvalue);
				current.rightchild=right;
				treenodequeue.offer(right);
				System.out.println("I am rightchild of value "+current.value+" , my value is "+right.value);
			}
		}
		return root;
	}
	
	/* for normal tree
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root==null)return 0;
        else if(root.val>=L&&root.val<=R)
            return root.val+rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);
        else return rangeSumBST(root.left,L,R)+rangeSumBST(root.right,L,R);
    }
    */
    //But with BST,It can be more efficient
    public static int rangeSumBST(TreeNode root, int L, int R){
        if(root==null)return 0;
        if(root.value>=L&&root.value<=R)
            return root.value+rangeSumBST(root.leftchild,L,R)+rangeSumBST(root.rightchild,L,R);
        else if(root.value<L)return rangeSumBST(root.rightchild,L,R);
        else return rangeSumBST(root.leftchild,L,R);
    }
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {10,5,15,3,7,null,18};
		int L=7;
		int R=15;
		System.out.println("Input nodes = "+Arrays.toString(nodes)+", L = "+L+", R = "+R);
        System.out.println("\nrangeSumBST is "+rangeSumBST(BuildTree(nodes),L,R));
	}

}