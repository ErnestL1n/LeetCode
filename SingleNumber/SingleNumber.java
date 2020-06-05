/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.136
public class SingleNumber {

	//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
	
	/**
	 * @param args
	 */
	
	//Bit Manipulation
	/*Concept:
	If we take XOR of zero and some bit, it will return that bit
	=>a¡ò0=a
	If we take XOR of two same bits, it will return 0
	=>a¡òa=0
	=>a¡òb¡òa=(a¡òa)¡òb=0¡òb=b
	So we can XOR all bits together to find the unique number.
	*/
	
	public static int SingleNumber(int[] nums) {
		int a=0;
		for(int i:nums)a^=i;
		
		return a;
	}
	
	public static void main(String[] args) {
		int[] nums= {1,5,7,1,3,3,7,9,10,10,2,9,2};
		System.out.println("Input array is "+Arrays.toString(nums));
		System.out.println("Single number is "+SingleNumber(nums));
	}

}
