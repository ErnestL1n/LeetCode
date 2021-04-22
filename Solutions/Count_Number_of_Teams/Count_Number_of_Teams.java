/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1395
class TreeNode{
    TreeNode left;
    TreeNode right;
    int val;
    int cnt_left;
    TreeNode(int value){
        this.val=value;
    }
}
public class Count_Number_of_Teams {

	//simple approach
    public static int numTeams(int[] rating) {
        int res=0;
        for(int i=0;i<rating.length;i++){
            int leftsmall=0,rightsmall=0,leftlarge=0,rightlarge=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])leftsmall++;
                else leftlarge++;
            }
            for(int k=i+1;k<rating.length;k++){
                if(rating[k]<rating[i])rightsmall++;
                else rightlarge++;
            }
            res+=leftsmall*rightlarge+leftlarge*rightsmall;
        }
        return res;
    }
    
    
    //counting approach
    private static int[] arr;
    public static int numTeamsDP(int[] rating) {
        arr = rating;
        return findLarge() + findSmall();
    }
    private static int findLarge() {
        int[] dp = new int[arr.length];
        // first loop, count of smaller on the left;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i]++;
                }
            }
        }
        //second loop, collct count of subsequence ending of i;
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    res += dp[j];
                }
            }
        }
        return res;
    }
    private static int findSmall() {  // same as count Larger
        int[] dp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    dp[i]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[i]) {
                    res += dp[j];
                }
            }
        }
        return res;
    }
	
    
    //balance tree approach
    public static int numTeamsAVL(int[] rating) {
        int res=0,length=rating.length;
        TreeNode left=new TreeNode(rating[0]);
        TreeNode right=new TreeNode(rating[length-1]);
        for(int i=1;i<length-1;++i)
            insert(right,rating[i]);
        for(int i=1;i<length-1;++i){
            remove(right, rating[i]);
            int leftSmall  = count(left, rating[i]), leftLarge = i - leftSmall;
            int rightSmall = count(right, rating[i]), rightLarge = (length - 1 - i - rightSmall) ;
            res += leftSmall * rightLarge + leftLarge * rightSmall;
            insert(left, rating[i]);
        }
        return res;     
    }
    
    private static int count(TreeNode root,int value){
        if(root==null)return 0;
        if(value<root.val)return count(root.left,value);
        return 1+root.cnt_left+count(root.right,value);
    }
    
    
    private static TreeNode insert(TreeNode root,int value){
        if(root==null)return new TreeNode(value);
        if(value<root.val){
            root.cnt_left++;
            root.left=insert(root.left,value);
        }
        else
            root.right=insert(root.right,value);
        return root;
    }
    
    
    private static TreeNode remove(TreeNode root, int value) {
    if (root == null)
        return null;
    if (root.val == value) {
        if (root.left == null)
            return root.right;
        TreeNode rightmost = root.left;
        while (rightmost.right != null)
            rightmost = rightmost.right;
        rightmost.right = root.right;
        return root.left;
    }
    if (value < root.val) {
        root.cnt_left--;
        root.left = remove(root.left, value);
    }
    else
        root.right = remove(root.right, value);
    return root;
    }
    
    
    
	public static void main(String[] args) {
		int[] rating1=new int[] {2,5,3,4,1};
		int[] rating2=new int[] {2,1,3};
		int[] rating3=new int[] {1,2,3,4};
		
		System.out.println("Each soldier is assigned a unique rating value ,rating array for soldier is "+Arrays.toString(rating1));
		System.out.println("Number of teams you can form is : "+numTeamsAVL(rating1));
		System.out.println("Each soldier is assigned a unique rating value ,rating array for soldier is "+Arrays.toString(rating2));
		System.out.println("Number of teams you can form is : "+numTeamsAVL(rating2));
		System.out.println("Each soldier is assigned a unique rating value ,rating array for soldier is "+Arrays.toString(rating3));
		System.out.println("Number of teams you can form is : "+numTeamsAVL(rating3));
	}
	

}