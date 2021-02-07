/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1518
public class Water_Bottles {

	/**
	 * @param args
	 */
    public static int numWaterBottlesOneLine(int numBottles, int numExchange) {
	        return numBottles + (numBottles - 1) / (numExchange - 1);
	    }
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int remainder = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += remainder;
        }
        return ans;
    }
	public static void main(String[] args) {
		

	}

}
