/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.5453 ?????  anyway it is called "Running Sum of 1d Array"
public class Running_Sum_of_1d_Array {

	/**
	 * @param args
	 */
	public static int[] runningSum(int[] nums) {
		int temp=nums[0];
		for(int i=1;i<nums.length;i++) {
			temp+=nums[i];
			nums[i]=temp;
		}
		return nums;
	}
	public static void main(String[] args) {
		int[] nums=new int[] {3,1,2,10,1};
		System.out.println("nums = "+Arrays.toString(nums));
		System.out.println("Running Sum of 1d Array is "+Arrays.toString(runningSum(nums)));
	}

}
