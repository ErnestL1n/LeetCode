/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1470
public class Shuffle_the_Array {

	/**
	 * @param args
	 */
	public static int[] shuffle(int[] nums, int n) {
        int[] temp=new int[nums.length];
        for(int i=0,j=0;i<n;i++,j+=2){
            temp[j]=nums[i];
            temp[j+1]=nums[i+n];
        }
        return temp;
    }
	public static void main(String[] args) {
		int[] nums=new int[] {2,5,1,3,4,7};  
		int n=3;
		System.out.println("Given nums array is "+Arrays.toString(nums)+", n is "+n);
		System.out.println("Shuffling the Array, it becomes "+Arrays.toString(shuffle(nums,n)));
	}

}
