/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1365
public class Smaller_Than_the_Current_Number {

	/**
	 * @param args
	 */
	public static int[] smallerNumbersThanCurrent(int[] nums) {
        int[] temp=new int[nums.length];
        int count[]=new int[101];
        for(int i=0;i<nums.length;i++)temp[i]=nums[i];
        Arrays.sort(temp);
        
        //after sorting
        for(int i=nums.length-1;i!=-1;i--)count[temp[i]]=i;
        for(int i=0;i<nums.length;i++)temp[i]=count[nums[i]];
        return temp;
    }
	public static void main(String[] args) {
		
		//Explanation: 
		//For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
		//For nums[1]=1 does not exist any smaller number than it.
		//For nums[2]=2 there exist one smaller number than it (1). 
		//For nums[3]=2 there exist one smaller number than it (1). 
		//For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
		
		int array1[]= {8,1,2,2,3};
		System.out.println("Input: nums = "+Arrays.toString(array1));
		System.out.println("Output: "+Arrays.toString(smallerNumbersThanCurrent(array1)));
		
		int array2[]= {7,7,7,7};
		System.out.println("Input: nums = "+Arrays.toString(array2));
		System.out.println("Output: "+Arrays.toString(smallerNumbersThanCurrent(array2)));
		
	}
	
	

}
