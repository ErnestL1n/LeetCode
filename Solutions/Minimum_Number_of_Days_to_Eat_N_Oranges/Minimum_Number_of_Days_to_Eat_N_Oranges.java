/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1553
public class Minimum_Number_of_Days_to_Eat_N_Oranges {

	/**
	 * @param args
	 */
    private Map<Integer,Integer> dp=new HashMap<>();
    public int minDays(int n) {
        if(n<=1)
            return n;
        if(!dp.containsKey(n))
            dp.put(n,1+Math.min(n%2+minDays(n/2),n%3+minDays(n/3)));
        return dp.get(n);
    }
	public static void main(String[] args) {
	}

}
