/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Weekly Contest 199 
//Leetcode.1530
class TreeNode{
	int val;
	TreeNode left,right;
	TreeNode(){
	};
	TreeNode(int value){
		this.val=value;
	}
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value;
		this.left=leftchild;
		this.right=rightchild;
	}
}
public class Number_of_Good_Leaf_Nodes_Pairs {

	/**
	 * @param args
	 */
	private static int res=0;
	public int countPairs(TreeNode root, int distance) {
		help(root,distance,0);
		return res;
	}
	//help function,which returns a set contains all leaf nodes's level(current node as root)
	private List<Integer> help(TreeNode root,int distance,int level){
		if(root==null)return new ArrayList<>();
		if(root.left==null&&root.right==null) {
			List<Integer> list=new ArrayList<>();
			list.add(level);
			return list;
		}
		List<Integer> left=help(root.left,distance,level+1);
		List<Integer> right=help(root.right,distance,level+1);
		
		for(int l:left)
			for(int r:right) {
				if((l-level+r-level)<=distance)
					++res;
			}
		left.addAll(right);
		return left;
	}
private static int result=0;
    public static int countPairsDFS(TreeNode root, int distance) {
        help(root,distance);
        return result;
    }
    private static int[] help(TreeNode root,int distance){
        if(root==null)return new int[distance+1];
        if(root.left==null&&root.right==null){
            int[] res=new int[distance+1];
            ++res[1];
            return res;
        }
        int[] left=help(root.left,distance);
        int[] right=help(root.right,distance);
        for(int l=0;l<left.length;++l)
            for(int r=0;r<right.length;++r){
                if(l+r<=distance)
                    res+=left[l]*right[r];
            }
        int[] res=new int[distance+1];
        for(int i=res.length-2;i>=1;i--){
            res[i+1] = left[i]+right[i];
        }
        return res;
    }
	public static void main(String[] args) {
	}

}
