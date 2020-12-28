/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.121
public class Best_Time_to_Buy_and_Sell_Stock {

	
	/**
	 * @param args
	 */
    public static int maxProfit(int[] prices) {
    	
        int maxprofit=0;
        
        /*naive solution first*/
        
        /*
        for(int i=0;i<prices.length;i++)
            for(int j=i+1;j<prices.length;j++)
                maxprofit=Math.max(maxprofit,prices[j]-prices[i]);
        return maxprofit;
        */
        
        
        /*One Pass*/
        
        /*
        int minPrice=Integer.MAX_VALUE;
        for(int i=0;i<prices.length;i++){
            if(minPrice>prices[i])
                minPrice=prices[i];
            else
                maxprofit=Math.max(maxprofit,prices[i]-minPrice);
        }
        return maxprofit;
        */
        
        
        
 
        
        
        int n = prices.length, maxProfitSoFar = 0;      
        // maxIncDiffSum[i] max sum of increasing difference ending at prices[i].
        int[] maxIncDiffSum = new int[n];

        for (int i = 1; i < n; i++) {
            maxIncDiffSum[i] = Math.max(0, maxIncDiffSum[i - 1] + prices[i] - prices[i - 1]);
            maxProfitSoFar = Math.max(maxProfitSoFar, maxIncDiffSum[i]);
        }
        
        return maxProfitSoFar;
        
    }
	public static void main(String[] args) {
		int[] prices=new int[] {7,1,5,3,6,4};
		System.out.println("an array ");
		System.out.println(Arrays.toString(prices));
		System.out.println("for which the ith element is the price of a given stock on day i.");
		System.out.println("At most one transaction ,finding the maximum profit is : ");
		System.out.println(maxProfit(prices));

	}

}
