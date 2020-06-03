/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1295
public class Find_Numbers_with_Even_Number_of_Digits {

	/**
	 * @param args
	 */
	public static int findNumbers(int[] nums) {
        int answer=0;
        for(int number:nums){
            int length=String.valueOf(number).length();
            if(length%2==0)
                answer++;
        }
        return answer;
    }
	public static void main(String[] args) {
		int[] nums=new int[] {12,345,2,6,7896};
		System.out.println("Input: nums = "+Arrays.toString(nums));
		System.out.println("Output is "+findNumbers(nums));
	}

}
