/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 * Goal:Just practice Java,cause I nearly forget this language  
 * reference(Main):https://www.callicoder.com/two-sum-problem/
 *
 */

import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;


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
	
	private static int[] Two_sum_TwoPassHashmap(int nums[],int value) {
		//Two pass Hash Table:O(n) a little faster than above one
		Map<Integer,Integer> numMap=new HashMap<>();
		for(int i=0;i<nums.length;i++) {
			numMap.put(nums[i],i);
		}
		for(int i=0;i<nums.length;i++) {
			
			int complement=value-nums[i];
			//if complement exists
			if(numMap.containsKey(complement)&& numMap.get(complement) != i)return new int[] {i,numMap.get(complement)};
		}
		return new int[] {};
	}
	
	//driver program to test the result
	
	public static void main(String[] args)
	{
		Scanner keyboard=new Scanner(System.in);
		
		System.out.println("Enter the element numbers");
		int n=keyboard.nextInt();
		
		int[] nums=new int[n];
		
		System.out.println("Enter the "+ n +" elements you want");
		for(int i=0;i<n;i++)
			nums[i]=keyboard.nextInt();
		
		System.out.println("Enter the value you want to find");
		int value=keyboard.nextInt();
		
		keyboard.close();
		
		
		//call the function you want to use here
		int indices[]=Two_sum_TwoPassHashmap(nums,value);
		
		
		if(indices.length==2)
			System.out.println(indices[0]+" "+indices[1]+" is the answer");
		else
			System.out.println("No solution found!");
	}
	
}
