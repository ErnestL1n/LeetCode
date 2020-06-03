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
	        int big1,big2;
	        if(nums[0]>nums[1]){
	            big1=nums[0];
	            big2=nums[1];
	            }
	        else if(nums[0]<nums[1]){
	            big1=nums[1];
	            big2=nums[0];
	        }
	        else{
	            big1=nums[0];
	            big2=nums[1];
	        }
	        for(int i=2;i<nums.length;i++){
	            if(nums[i]>big1){
	                big2=big1;
	                big1=nums[i];
	            }
	            else if(nums[i]==big1&&big1>big2)
	                big2=nums[i];
	            else if(nums[i]>big2)
	                big2=nums[i];
	        }
	        return (big1-1)*(big2-1);
	    }
	public static void main(String[] args) {
		int[] nums=new int[] {1,5,4,5};
		System.out.println("Input: nums = "+Arrays.toString(nums));
		System.out.println("Output: "+maxProduct(nums));
	}

}
