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
	private static int[] Two_sum_bruteforce(int[] nums,int value) {
		//naive approach O(n^2)
		for(int i=0;i<nums.length;i++)
			for(int j=i+1;j<nums.length;j++) {
				if(nums[i]+nums[j]==value)
					return new int[] {i,j};
			}
		//otherwise=>return empty set
		return new int[] {};
	}
	
	private static int[] Two_sum_OnePassHashmap(int nums[],int value) {
		//One pass Hash Table:O(n)
		Map<Integer,Integer> numMap=new HashMap<>();
		for(int i=0;i<nums.length;i++) {
			int complement=value-nums[i];
			
			//if complement exists
			if(numMap.containsKey(complement))return new int[] {i,numMap.get(complement)};
			else numMap.put(nums[i], i);
		}
		return new int[] {};
	
	}
	
	private static int[] Two_sum_TwoPassHashmap(int nums[],int target) {
		//Two pass Hash Table:O(n) a little faster than above one
		//at first iteration,it must do into map
		HashMap<Integer,Integer> map=new HashMap<>();
		map.put(nums[0],0);
		for(int i=1;i<nums.length;i++) {
			if(map.containsKey(target-nums[i]))
				return new int[] {i,map.get(target-nums[i])};
			map.put(nums[i], i);
		}
		return null;
	}
	
	public static void main(String[] args) {
		
	}
	
}