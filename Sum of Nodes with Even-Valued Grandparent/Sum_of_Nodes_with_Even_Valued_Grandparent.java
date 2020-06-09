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
	
	public static int sumEvenGrandparent(TreeNode root) {
        return find(root,null,null);
    }
    private static int find(TreeNode current,TreeNode parent,TreeNode grandparent){
        int sum=0;
        if(current==null)return 0;
        if(grandparent!=null&&grandparent.value%2==0){
            sum+=current.value;
        }
        sum+=find(current.left,current,parent);
        sum+=find(current.right,current,parent);
        return sum;
    }
    
	
	public static void main(String[] args) {
		
		
		Integer[] nodes = new Integer[]{6,7,8,2,7,1,3,9,null,1,4,null,null,null,5};
		
		
		System.out.println("\nsumEvenGrandparent is "+sumEvenGrandparent(Build(nodes)));
		
	}

}
