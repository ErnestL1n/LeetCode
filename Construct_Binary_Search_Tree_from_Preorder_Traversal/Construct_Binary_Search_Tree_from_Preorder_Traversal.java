/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//LeetCode.1008
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int val){this.value=val;};
	TreeNode(int value,TreeNode left,TreeNode right){
		this.value=value;this.leftchild=left;this.rightchild=right;
	}
}
public class Construct_Binary_Search_Tree_from_Preorder_Traversal {

	/**
	 * @param args
	 */
	/*public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null||nodes.length==0)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
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
	}*/

	public static int getTreeSize(TreeNode root) {
		if(root==null)return 0;
		return 1+getTreeSize(root.leftchild)+getTreeSize(root.rightchild);
	}
	public static void printTree(TreeNode root) {
		int TreeSize=getTreeSize(root);
		if(root==null||TreeSize==0)return;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		treenodequeue.offer(root);
		System.out.println("I am root , my value is "+root.value);
		TreeSize--;
		while(TreeSize!=0) {
			TreeNode current=treenodequeue.poll();
			TreeNode left=current.leftchild;
			TreeNode right=current.rightchild;
			if(left!=null) {
				treenodequeue.offer(left);
				System.out.println("I am  leftchild of "+current.value+" my value is "+left.value);
				TreeSize--;
			}
			if(right!=null) {
				treenodequeue.offer(right);
				System.out.println("I am rightchild of "+current.value+" my value is "+right.value);
				TreeSize--;
			}
		}
	}
	
	//using Stack
	public static TreeNode bstFromPreorder(int[] preorder) {
	    Stack<TreeNode> stack=new Stack<>();
        TreeNode root=new TreeNode(preorder[0]);
        stack.push(root);
        for(int i=1;i<preorder.length;i++){
            //left child case
            TreeNode current=new TreeNode(preorder[i]);
            if(current.value<stack.peek().value){
                stack.peek().leftchild=current;
            }
            //rightchild case find its parent
            else{
                TreeNode parent=new TreeNode();
                while(!stack.isEmpty()&&preorder[i]>stack.peek().value){
                    //pop up the unuse nodes until get the parent
                    parent=stack.pop();
                }
                parent.rightchild=current;
            }
                            stack.push(current);
        }
        return root;
	}
	static int index=0;
	public static TreeNode bstFromPreorderRecursive(int[] preorder) {
		if(preorder.length==0)return null;
		return bstFromPreHelp(preorder,Integer.MAX_VALUE);
	}
	public static TreeNode bstFromPreHelp(int[] preorder,int bound) {
		if(preorder.length==index||preorder[index]>bound)return null;
		TreeNode root=new TreeNode(preorder[index++]);
		root.leftchild=bstFromPreHelp(preorder,root.value);
		root.rightchild=bstFromPreHelp(preorder,bound);
		return root;
	}
	public static TreeNode bstFromPreorderRecursiveRevisedVersion(int[] preorder) {
		if(preorder.length==0)return null;
		return bstFromPreorderRecursiveRevisedVersionHelp(preorder,Integer.MAX_VALUE,new int[] {0});
		
	}
	public static TreeNode bstFromPreorderRecursiveRevisedVersionHelp(int[] preorder,int bound,int[] index) {
		if(preorder.length==index[0]||preorder[index[0]]>bound)return null;
		TreeNode root=new TreeNode(preorder[index[0]++]);
		root.leftchild=bstFromPreorderRecursiveRevisedVersionHelp(preorder,root.value,index);
		root.rightchild=bstFromPreorderRecursiveRevisedVersionHelp(preorder,bound,index);
		return root;
	}
	
	public static void main(String[] args) {
		int[] preorder=new int[] {8,5,1,7,10,12};
		System.out.println("Preorder traversal of the BST is "+Arrays.toString(preorder));
		TreeNode root=bstFromPreorderRecursiveRevisedVersion(preorder);
		System.out.println("Build BST from given preorder traversal is ");
		printTree(root);
	}

}
