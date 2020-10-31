/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1402
public class Reducing_Dishes {

	/**
	 * @param args
	 */
	//brilliant solution provided by https://leetcode.com/lee215/
	public int maxSatisfaction(int[] s) {
        Arrays.sort(s);
        int res=0,total=0;
        for(int i=s.length-1;i>=0&&s[i]+total>0;--i){
            total+=s[i];
            res+=total;
        }
        return res;
    }
	public static void main(String[] args) {
		int[] satisfaction = new int[]{-2,5,-1,0,3,-3};
		System.out.println("satisfaction of dishes are " +Arrays.toString(satisfaction));
		//Like-time coefficient of a dish is defined as the time taken to cook that dish 
		//including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

		System.out.println("Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation is ");
		System.out.println(maxSatisfaction(satisfaction));
		
		
	}

}
