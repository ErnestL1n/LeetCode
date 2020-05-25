/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.*;
public class KnapSack {
	//for 0-1 knapsack problem
	
	static int max(int a,int b) {return (a>b)?a:b;}
	
	static int[][] ZOKnapSack(int bagWeight,int itemsweight[],int values[],int n) {
		
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
		
		return M;
	}
	
	private static Set<Integer> finditemschosen(int M[][],int n,int bagWeight,int itemsweight[]) {
		Set<Integer> s=new HashSet<Integer>();
		//empty set is initialized
		s.addAll(Arrays.asList(new Integer[] {})); 
		int weight=bagWeight;
		for(int i=n;i>=1;i--) {
			//i is put into the bag
			if(M[i][weight]>M[i-1][weight]) {
				weight-=itemsweight[i-1];
				s.addAll(Arrays.asList(new Integer[] {i})); 
			}
		}
		return s;
	}

	
	public static void main(String[] args) {

        int values[] = new int[] { 50, 60, 140 }; 
        int itemsweight[] = new int[] { 5, 10, 20 }; 
        int W = 30; 
        int n = values.length; 
        int bag[][]=ZOKnapSack(W, itemsweight, values, n);
        
        System.out.println("There are "+ n +" items "); 
        
        System.out.println("Items values  are:"+ Arrays.toString(values)); 
        
        System.out.println("Items weights are:"+ Arrays.toString(itemsweight)); 
        
        System.out.println("Bag capacity is " + W);
        
        System.out.println("The 0-1 KnapSack solution is:" + bag[n][W]); 
        
        System.out.println("Items choose are items " + finditemschosen(bag, n, W, itemsweight)); 

	}

}
