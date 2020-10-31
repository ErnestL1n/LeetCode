/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1512
public class Number_of_Good_Pairs {

	/**
	 * @param args
	 */
	public int numIdenticalPairs(int[] nums) {
	    int cnt[] = new int[101], res = 0;
	    for (var n: nums)
	        ++cnt[n];
	    for (int i = 0; i <= 100; ++i)
	        res += cnt[i] * (cnt[i] - 1) / 2;
	    return res;     
	}
	public static void main(String[] args) {

	}

}
