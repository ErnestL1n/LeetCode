/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.*;
//Leetcode.1161
//reference:https://stackoverflow.com/users/11625748/steven   

class TreeNode{
    int value;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int value) { this.value = value;}
    TreeNode(int value, TreeNode left, TreeNode right) {
        this.value = value;
        this.left = left;
        this.right = right;
     }
}


public class Maximum_Level_Sum_of_a_Binary_Tree {

	/**
	 * @param args
	 */
	public static int maxLevelSum(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<>();
        if(root==null)return 0;
        queue.offer(root);
        int temp=Integer.MIN_VALUE;
        int treelevel=0;
        int maxlevel=0;
        int sum=0;
        while(!queue.isEmpty()){
            treelevel++;
            int size=queue.size();
            for(int i=0;i<size;i++){
                TreeNode node=queue.poll();
                sum+=node.value;
                if(node.left!=null)queue.offer(node.left);
                if(node.right!=null)queue.offer(node.right);
            }
            if(sum>temp){
                temp=sum;
                maxlevel=treelevel;
            }
            sum=0;
        }
        return maxlevel;
    }
	
	public static TreeNode Build(Integer[] array) {
        if (array == null || array.length==0) {
            return null;
        }

        Queue<TreeNode> treeNodeQueue = new LinkedList<>();
        Queue<Integer>  integerQueue  = new LinkedList<>();
        for (int i = 1; i < array.length; i++) {
            integerQueue.offer(array[i]);
        }

        TreeNode root = new TreeNode(array[0]);
        treeNodeQueue.offer(root);
        System.out.println("I am root ,value is "+root.value);
        while (!integerQueue.isEmpty()){
        	//Binary tree begins from left
            Integer leftVal  = integerQueue.isEmpty() ? null : integerQueue.poll();
            Integer rightVal = integerQueue.isEmpty() ? null : integerQueue.poll();
            TreeNode current = treeNodeQueue.poll();
            if (leftVal !=null) {
                    TreeNode left = new TreeNode(leftVal);
                    current.left = left;
                    treeNodeQueue.offer(left);
                    System.out.println("I am leftchild  of value "+current.value+" , my value is "+left.value);
            }
            if (rightVal !=null){
                    TreeNode right = new TreeNode(rightVal);
                    current.right = right;
                    treeNodeQueue.offer(right);
                    System.out.println("I am rightchild of value "+current.value+" , my value is "+right.value);
            }
        }
        return root;
    }
	
	
	
	public static void main(String[] args) {
		Integer[] array = new Integer[]{1,7,0,7,-8,null,null};
		System.out.println("Input  array is: \n"+Arrays.toString(array));
		System.out.println("\nMaxSum level is "+maxLevelSum(Build(array)));

	}

}
