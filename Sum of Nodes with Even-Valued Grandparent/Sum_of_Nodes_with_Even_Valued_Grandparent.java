/**
 * 
 */
package github.com.ErnestL1n;


import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1315

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val;}
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
     }
}

public class Sum_of_Nodes_with_Even_Valued_Grandparent {

	/**
	 * @param args
	 */
	public static TreeNode Build(Integer[] array) {
        if (array == null || array.length==0) {
            return null;
        }

        Queue<TreeNode> treeNodeQueue = new LinkedList<>();
        Queue<Integer>  integerQueue  = new LinkedList<>();
        for (int i = 1; i < array.length; i++) {
            integerQueue.offer(array[i]);
        }

        TreeNode treeNode = new TreeNode(array[0]);
        treeNodeQueue.offer(treeNode);

        while (!integerQueue.isEmpty()){
        	//Binary tree begins from left
            Integer leftVal  = integerQueue.isEmpty() ? null : integerQueue.poll();
            Integer rightVal = integerQueue.isEmpty() ? null : integerQueue.poll();
            TreeNode current = treeNodeQueue.poll();
            if (leftVal !=null) {
                    TreeNode left = new TreeNode(leftVal);
                    current.left = left;
                    treeNodeQueue.offer(left);
            }
            if (rightVal !=null){
                    TreeNode right = new TreeNode(rightVal);
                    current.right = right;
                    treeNodeQueue.offer(right);
            }
        }
        return treeNode;
    }
	
	public static int sumEvenGrandparent(TreeNode root) {
        return find(root,null,null);
    }
    private static int find(TreeNode current,TreeNode parent,TreeNode grandparent){
        int sum=0;
        if(current==null)return 0;
        if(grandparent!=null&&grandparent.val%2==0){
            sum+=current.val;
        }
        sum+=find(current.left,current,parent);
        sum+=find(current.right,current,parent);
        return sum;
    }
    
	
	public static void main(String[] args) {
		
		
		Integer[] nodes = new Integer[]{6,7,8,2,7,1,3,9,null,1,4,null,null,null,5};
		
		System.out.println("Input  array is: "+Arrays.toString(nodes));
		System.out.println("Output is "+sumEvenGrandparent(Build(nodes)));
		
	}

}
