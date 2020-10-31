/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1464
public class Maximum_Product_of_Two_Elements_in_an_Array {

	/**
	 * @param args
	 */
	//straight forward,but efficient
	 public static int maxProduct(int[] nums) {
		    //store the first and second largest ones of the array
	        int first=Integer.MIN_VALUE;
	        int second=first;
	        for(int num:nums) {
	        	if(num>=first) {
	        		second=first;
	        		first=num;
	        	}
	        	else if(num>second)
	        		second=num;
	        }
	        return (first-1)*(second-1);
	    }
	 
	 //sorting is much slower
	 public int maxProductSort(int[] nums) {
	        Arrays.sort(nums);
	        return (nums[nums.length-1]-1)*(nums[nums.length-2]-1);
	    }
	 
	 
	public static void main(String[] args) {
		int[] nums=new int[] {1,5,4,5};
		System.out.println("Given the array of integers nums : "+Arrays.toString(nums)+" you will choose two different indices i and j of that array ");
		System.out.println("Return the maximum value of (nums[i]-1)*(nums[j]-1) ");
		System.out.println("=> "+maxProduct(nums));
	}

}
