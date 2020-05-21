/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author WEI TING
 *
 */
import java.util.*;
public class KnapSack {
	//for 0-1 knapsack problem
	
	static int max(int a,int b) {return (a>b)?a:b;}
	
	static int ZOKnapSack(int bagWeight,int itemsweight[],int values[],int n) {
		
		int M[][]=new int[n+1][bagWeight+1];
		
		for(int w=0;w<=bagWeight;w++)M[0][w]=0;
		
		//Dynamic programming to build up array
		for(int i=1;i<=n;i++)
			for(int w=0;w<=bagWeight;w++) {
				
				
				//NOTE!!value&itemsweight array are "i-1" when M["i"][w] reaches
				//can't put into the bag
				if(itemsweight[i-1]>w)M[i][w]=M[i-1][w];
				
				//max(choose "i" item or not choose)
				else M[i][w]=max(M[i-1][w],values[i-1]+M[i-1][w-itemsweight[i-1]]);
					
			}
		
		return M[n][bagWeight];
	}

	
	public static void main(String[] args) {

        int values[] = new int[] { 60, 100, 120 }; 
        int itemsweight[] = new int[] { 10, 20, 30 }; 
        int W = 50; 
        int n = values.length; 
        System.out.println(ZOKnapSack(W, itemsweight, values, n)); 
	

	}

}
