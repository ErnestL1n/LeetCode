/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1523
public class Count_Odd_Numbers_in_an_Interval_Range {

	/**
	 * @param args
	 */
	public static int countOdds(int low, int high) {
        if(low%2==0&&high%2==0)return (high-low)/2;
        else return (high-low)/2+1;
    }
	public static void main(String[] args) {
		

	}

}
