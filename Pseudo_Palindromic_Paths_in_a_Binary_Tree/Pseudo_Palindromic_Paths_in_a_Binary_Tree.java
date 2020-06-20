/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1457
//reference:https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/648534/JavaC%2B%2BPython-At-most-one-odd-occurrence
//provided by https://leetcode.com/lee215/
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int value){
		this.val=value;
	}
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value;
		this.left=leftchild;
		this.right=rightchild;
	}
}
public class Pseudo_Palindromic_Paths_in_a_Binary_Tree {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null&&nodes.length==0)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
		TreeNode root=new TreeNode(nodes[0]);
		treenodequeue.offer(root);
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		while(!integerqueue.isEmpty()) {
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
		int treesize=getTreeSize(root);
		Queue<TreeNode> treenodequeue=new LinkedList<>();
	    treenodequeue.offer(root);
	    System.out.println("I am root , my value is "+root.val);
	    treesize--;
	    while(treesize!=0) {
	    	TreeNode current=treenodequeue.poll();
	    	TreeNode leftchild=current.left;
	    	TreeNode rightchild=current.right;
	    	if(leftchild!=null) {
	    		treenodequeue.offer(leftchild);
	    		System.out.println("I am  leftchild of "+current.val+" my value is "+leftchild.val);
	    		treesize--;
	    	}
	    	if(rightchild!=null) {
	    		treenodequeue.offer(rightchild);
	    		System.out.println("I am rightchild of "+current.val+" my value is "+rightchild.val);
	    		treesize--;
	    	}
	    }
	}
	
	//Method 1:Use Array :It runs 8ms, memory usage:57.9 MB in Leetcode
	//Time O(NK) or O(N)
	//Space O(K + H)
	private static int count=0;
	public static int pseudoPalindromicPathsMethod1 (TreeNode root) {
		//constraint:digit:1~9
		find(root,new int[10]);
		return count;
	}
	public static void find(TreeNode root,int[] freq) {
		if(root==null)return;
		freq[root.val]++;
		//leaf nodes
		if(root.left==null&&root.right==null) {
			int flag=0;
			for(int i=1;i<=9;i++)
				if(freq[i]%2!=0)flag++;
			if(flag<=1)count++;
		}
		find(root.left,freq);
		find(root.right,freq);
		//minus freq back to the branch node
		freq[root.val]--;
	}
	
	
	//Method 2:Use HashSet:It runs 64 ms, memory usage:55.9 MB in Leetcode,much slower
	//Time O(N)
	//Space O(K + H)
    static int hashcount = 0;
    public int pseudoPalindromicPaths (TreeNode root) {
        dfs(root, new HashSet<>());
        return hashcount;
    }
    private void dfs(TreeNode node, Set<Integer> set) {
        if(node !=null) {
            if(set.contains(node.val)) set.remove(node.val); else set.add(node.val);
            if(node.left ==null && node.right == null) {
                if(set.size() <=1) hashcount++;
            } else {
                dfs(node.left, new HashSet<>(set));
                dfs(node.right, new HashSet<>(set));                
            }
        }
    }
    
    
	
	//Method 3:Use an integer:It runs 2 ms, memory usage:57.8 MB in Leetcode
	//Time O(N)
	//Space O(K + H)
	public static int pseudoPalindromicPathsMethod3(TreeNode root) {
		return dfs(root, 0);
	}
	private static int dfs(TreeNode root, int count) {
        if (root == null) return 0;
        count ^= 1 << (root.val - 1);
        int res = dfs(root.left, count) + dfs(root.right, count);
        if (root.left == root.right && (count & (count - 1)) == 0) res++;
        return res;
    }
	
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {2,3,1,3,1,null,1};
		TreeNode root=BuildTree(nodes);
		printTree(root);
		System.out.println("Number of pseudo-palindromic paths going from the root node to leaf nodes is "+pseudoPalindromicPathsMethod3(root));
		
	}

}
