/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1
//The improved solution is provided by:https://leetcode.com/jiaming2/
//Its idea is putting into HashMap not at the first time,but at the time when it doesn't find in the HashMap
public class Two_Sum {
	//return indices
	public static int[] Two_sum_bruteforce(int[] nums,int value) {
		//naive approach O(n^2)
		for(int i=0;i<nums.length;i++)
			for(int j=i+1;j<nums.length;j++) {
				if(nums[i]+nums[j]==value)
					return new int[] {i,j};
			}
		//otherwise=>return empty set
		return new int[] {};
	}
	

	
	public static int[] Two_sum_TwoPassHashmap(int nums[],int target) {
		//Two pass Hash Table:O(n) a little faster than above one
		HashMap<Integer,Integer> map=new HashMap<>();
		//at first iteration,it must do into map
		map.put(nums[0],0);
		for(int i=1;i<nums.length;i++) {
			if(map.containsKey(target-nums[i]))
				return new int[] {i,map.get(target-nums[i])};
			map.put(nums[i], i);
		}
		return null;
	}
	
	public static void main(String[] args) {
		int[] nums=new int[] {2, 7, 11, 15 };
		int target=9;
		System.out.println("Given nums is "+Arrays.toString(nums)+" , target is "+target);
		System.out.println("Indices of the two numbers such that they add up to a specific target are "+Arrays.toString(Two_sum_TwoPassHashmap(nums,target)));
	}
	
}