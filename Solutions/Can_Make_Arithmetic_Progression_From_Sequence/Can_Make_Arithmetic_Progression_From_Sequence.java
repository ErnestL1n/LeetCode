/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1502
public class Can_Make_Arithmetic_Progression_From_Sequence {

	//method 1 :using hashset and difference
	//1. Find the max and min of arr and compute the average difference;
	//2. Put all numbers into a HashSet;
	//3. Start from the min, add the average difference to make the next number in the arithmetic sequence,
	//   check one by one if it is in the HashSet; if any one not in, return false; otherwise, return true.
	//   Time: O(n), space: O(n)
	//provided by:https://leetcode.com/rock/
    public static boolean canMakeArithmeticProgressionDiff(int[] arr) {
        Set<Integer> seen=new HashSet<>();
        int n=arr.length,min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        for(int a:arr){
            min=Math.min(a,min);
            max=Math.max(a,max);
            seen.add(a);
        }
        int diff=max-min;
        if(diff%(n-1)!=0)return false;
        diff/=(n-1);
        while(--n > 0){
            if(!seen.contains(min))
                return false;
            min+=diff;
        }
        return true;
    }
	
	
	
	//method 2 : sorting method
	//Time: O(nlogn), space: O(1) if excluding space used during sort.
    public static boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        for(int i=1;i<arr.length-1;++i){
            if(arr[i-1]-arr[i]!=arr[i]-arr[i+1])
                return false;
        }
        return true;
    }
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int[] arr = new int[] {3,5,1};
		System.out.println("Given an array of numbers "+Arrays.toString(arr));
		System.out.println("Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.");
		System.out.println("=> "+canMakeArithmeticProgressionDiff(arr));

	}

}
