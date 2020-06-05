/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1313

public class Decompress_Run_Length_Encoded_List {

	/**
	 * @param args
	 */
    public static int[] decompressRLElist(int[] nums) {
        int answerlength=0;
        //add frequency
        for(int i=0;i<nums.length;i+=2)answerlength+=nums[i];
        //build array
        int[] answer=new int[answerlength];
        int begin=0;
        for(int i=0;i<nums.length;i+=2){
            // Makes elements from from_Index (inclusive) to to_Index (exclusive) equal to array
            Arrays.fill(answer,begin,begin+nums[i],nums[i+1]);
            begin+=nums[i];
        }
        return answer;
    }

	public static void main(String[] args) {
		int[] nums=new int[] {1,2,3,4};
		System.out.println(" Input array is "+Arrays.toString(nums));
		System.out.println("Output array is "+Arrays.toString(decompressRLElist(nums)));
	}

}
