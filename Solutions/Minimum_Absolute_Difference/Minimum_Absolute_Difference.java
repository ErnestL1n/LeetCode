/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1200
public class Minimum_Absolute_Difference {

	/**
	 * @param args
	 */
	public static List<List<Integer>> minimumAbsDifference(int[] arr){
		List<List<Integer>> answer=new ArrayList<>();
		if(arr==null)return answer;
		
		Arrays.sort(arr);
		int MinAbs=Integer.MAX_VALUE;
		for(int i=0;i<arr.length-1;i++)MinAbs=Math.min(MinAbs, arr[i+1]-arr[i]);
		for(int i=0;i<arr.length-1;i++)
			if(arr[i+1]-arr[i]==MinAbs)
				answer.add(Arrays.asList(arr[i],arr[i+1]));
		return answer;
		
	}
	public static void main(String[] args) {
		int[] arr=new int[] {4,2,1,3};
		System.out.println("Input array is "+Arrays.toString(arr));
		System.out.println("Minimum Absolute Difference pairs are "+minimumAbsDifference(arr));

	}

}
