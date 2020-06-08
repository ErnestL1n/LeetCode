/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.701
class TreeNode{
	int value;
	TreeNode leftchild;
	TreeNode rightchild;
	TreeNode(){};
	TreeNode(int value){
		this.value=value;
	}
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.value=value;
		this.leftchild=leftchild;
		this.rightchild=rightchild;
	}
}
public class Insert_into_a_Binary_Search_Tree {

	/**
	 * @param args
	 */
	public TreeNode insertIntoBST(TreeNode root, int val) {
		//empty tree,new node be the root
        if(root==null){
            root=new TreeNode(val);
            return root;
        }
        if(val<root.value)root.leftchild=insertIntoBST(root.leftchild,val);
        else if(val>root.value)root.rightchild=insertIntoBST(root.rightchild,val);
        
        
        return root;
    }
	public static void main(String[] args) {
		

	}

}
