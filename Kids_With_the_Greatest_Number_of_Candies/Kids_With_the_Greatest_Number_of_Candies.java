/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1431
public class Kids_With_the_Greatest_Number_of_Candies {

	/**
	 * @param args
	 */
	public static List<Boolean> kidsWithCandies(int[] candies,int extraCandies){
		int max=Integer.MIN_VALUE;
		List<Boolean> answer=new ArrayList<Boolean>();
		for(int i=0;i<candies.length;i++)if(max<candies[i])max=candies[i];
		for(int i=0;i<candies.length;i++) {
			if(candies[i]+extraCandies<max)answer.add(false);
			else answer.add(true);
		}
		return answer;
	}
	public static void main(String[] args) {
		int[] candies=new int[] {2,3,5,1,3};
		int extraCandies=3;
		System.out.println("Input: candies = "+Arrays.toString(candies)+", extraCandies = "+ extraCandies); 
		System.out.println("Output: "+kidsWithCandies(candies,extraCandies));

	}
	

}
