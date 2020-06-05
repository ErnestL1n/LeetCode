/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1379
//it is difficult to understand this question
//actually I don't know what this problem is asking for
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){
		this.value=value;
	}
}
public class Find_a_Corresponding_Node_of_a_Binary_Tree_in_a_Clone_of_That_Tree {

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
		while(!integerqueue.isEmpty()) {
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode current=treenodequeue.poll();
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
	public static final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (original == null) {
		return null;
	}
	if (original == target) {
		return cloned;
	}

	TreeNode node1 = getTargetCopy(original.leftchild, cloned.leftchild, target);
	if(node1!=null){
        return node1;
    }
    TreeNode node2 = getTargetCopy(original.rightchild, cloned.rightchild, target);
	    
       return node2; 
    }
	public static TreeNode getNode(TreeNode root,int targetvalue) {
		if(root==null)return null;
		if(root.value==targetvalue)return root;
		else {
		TreeNode left=getNode(root.leftchild,targetvalue);
		if(left!=null)return left;
		else return getNode(root.rightchild,targetvalue);
		}
	}
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {8,null,6,null,5,null,4,null,3,null,2,null,1};
		int targetvalue=4;
		TreeNode original=BuildTree(nodes);
		TreeNode cloned=BuildTree(nodes);
		TreeNode target=getNode(original,targetvalue);
		System.out.println("Input tree is "+Arrays.toString(nodes)+ ",target is value "+targetvalue);
		System.out.println("Output is "+getTargetCopy(original,cloned,target).value);

	}

}
