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
	
	
	//using HashMap
	public static int[] smallerNumbersThanCurrentHash(int[] nums) {
		HashMap<Integer,Integer> map=new HashMap<>();
		int[] temp=nums.clone();
		Arrays.sort(temp);
		for(int i=0;i<nums.length;i++)map.putIfAbsent(temp[i], i);
		for(int i=0;i<nums.length;i++)temp[i]=map.get(nums[i]);
		return temp;
	}
	
	//O(n) without sorting
	public static int[] smallerNumbersThanCurrentHashNosort(int[] nums) {
		int[] res=new int[nums.length];
		int[] count=new int[101];
		for(int i=0;i<nums.length;i++)count[nums[i]]++;
		for(int i=1;i<100;i++)count[i]+=count[i-1];
		for(int i=0;i<nums.length;i++) {
			if(nums[i]==0)res[i]=0;
			else
				//how many numbers are there before my value
				res[i]=count[nums[i]-1];
		}
		return res;
	}
    
	
	
	public static void main(String[] args) {
		
		
		int array1[]= {8,1,2,2,3};
		System.out.println("Given the array1 = "+Arrays.toString(array1));
		System.out.println("for each nums[i] find out how many numbers in the array are smaller than it: "+Arrays.toString(smallerNumbersThanCurrentHashNosort(array1)));
		
		int array2[]= {7,7,7,7};
		System.out.println("Given the array2 = "+Arrays.toString(array2));
		System.out.println("for each nums[i] find out how many numbers in the array are smaller than it: "+Arrays.toString(smallerNumbersThanCurrentHashNosort(array2)));
		
	}
	
	

}