/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
import java.util.stream.Collectors;
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
	
	//streaming implementation is provided by:https://leetcode.com/rock
	public static List<Boolean> kidsWithCandiesStream(int[] candies, int extraCandies) {
        int max = Arrays.stream(candies).max().getAsInt();
        return Arrays.stream(candies).mapToObj(candy -> candy + extraCandies >= max).collect(Collectors.toList());
    }
	
	
	public static void main(String[] args) {
		int[] candies=new int[] {2,3,5,1,3};
		int extraCandies=3;
		System.out.println("Candies array for ith kid : "+Arrays.toString(candies)+", extraCandies are : "+ extraCandies); 
		System.out.println("For each kid check if there is a way to distribute extraCandies among the kids such that he can have the greatest number of candies among them. ");
		System.out.println(kidsWithCandies(candies,extraCandies));

	}
	

}