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
	
	public static boolean isUnivalTree(TreeNode root) {
        if(root==null)return true;
        if(root.left!=null&&root.left.val!=root.val)return false;
        if(root.right!=null&&root.right.val!=root.val)return false;
        return isUnivalTree(root.left)&&isUnivalTree(root.right);
    }
	public static void main(String[] args) {
		

	}

}
