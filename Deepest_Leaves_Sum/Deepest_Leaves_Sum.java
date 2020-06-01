/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//reference:https://leetcode.com/gthor10/

//Leetcode.1302
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){this.value=value;};
	TreeNode(TreeNode leftchild,TreeNode rightchild,int value){
		this.leftchild=leftchild;
		this.rightchild=rightchild;
		this.value=value;
	}
}

public class Deepest_Leaves_Sum {
	
	private static int sum=0,maxlevel=0;
	
	//given Integer[] to build tree
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null||nodes.length==0)return null;
		Queue<TreeNode> TreeNodeQueue=new LinkedList<>();
		Queue<Integer> IntegerQueue= new LinkedList<>();
		for(int i=1;i<nodes.length;i++)IntegerQueue.offer(nodes[i]);
		
		TreeNode treenode=new TreeNode(nodes[0]);
		TreeNodeQueue.offer(treenode);
		while(!IntegerQueue.isEmpty()) {
			Integer leftvalue=IntegerQueue.isEmpty()?null:IntegerQueue.poll();
			Integer rightvalue=IntegerQueue.isEmpty()?null:IntegerQueue.poll();
			TreeNode current=TreeNodeQueue.poll();
			if(leftvalue!=null) {
				TreeNode left=new TreeNode(leftvalue);
				current.leftchild=left;
				TreeNodeQueue.offer(left);
			}
			if(rightvalue!=null) {
				TreeNode right=new TreeNode(rightvalue);
				current.rightchild=right;
				TreeNodeQueue.offer(right);
			}
			
		}
		return treenode;
		
	}
	public static int deepestLeavesSum(TreeNode root) {
        getsum(root,1);
        return sum;
    }
	public static void getsum(TreeNode node,int level) {
		if(node==null) return;
		
		//if this is the leave node,root level begins at 1
		if(node.leftchild==null&&node.rightchild==null&&level>=maxlevel) {
			// ">" case =>new deepest, start over with the sum
			if(level>maxlevel) {
				sum=node.value;
				maxlevel=level;
			}
			// "=" case =>same as current deepest - accumulate this node value
			else {
				sum+=node.value;
			}
		}
		
		//recursively compute left and right
		
		getsum(node.leftchild,level+1);
		getsum(node.rightchild,level+1);
	}
	

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {1,2,3,4,5,null,6,7,null,null,null,null,8};
		System.out.println("Input nodes = "+Arrays.toString(nodes));
		System.out.println("Output is "+deepestLeavesSum(BuildTree(nodes)));
		

	}

}
