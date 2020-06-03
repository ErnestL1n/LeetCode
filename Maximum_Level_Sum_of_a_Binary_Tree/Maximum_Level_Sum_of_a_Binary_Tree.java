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
                sum+=node.val;
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
        return root;
    }
	
	
	
	public static void main(String[] args) {
		Integer[] array = new Integer[]{39608,null,-34332,84856,62101,98129,null,null,-26118,null,57785,-75141,null,null,-63491,-63367};
		
		
		
		System.out.println("Input  array is: "+Arrays.toString(array));
		System.out.println("Output level is "+maxLevelSum(Build(array)));

	}

}
