/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1389
public class Create_Target_Array_in_the_Given_Order {

	/**
	 * @param args
	 */
	public static int[] createTargetArray(int[] nums, int[] index) {
		//use container
		ArrayList<Integer> display=new ArrayList<>();
		//length is a field on any array
		for(int i=0;i<nums.length;i++) {
			display.add(index[i],nums[i]);
		}
		//note:size() isn't constant
		//size() is a method specified in java.util.Collection, 
		//which is then inherited by every data structure in the standard library.
		int[] answer=new int[display.size()];
		 //get nums from the index and put into answer[]
		for(int i=0;i<display.size();i++)
			answer[i]=display.get(i);
		
		return answer;
	}
	public static void main(String[] args) {
		int[] nums=new int[] {1,2,3,4,0};
		int[] index=new int[] {0,1,2,3,0};
		System.out.println("Input: nums = "+Arrays.toString(nums)+", index = "+Arrays.toString(index));
		System.out.println("Output is "+Arrays.toString(createTargetArray(nums,index)));
	}

}
