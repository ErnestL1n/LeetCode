/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1304
public class Find_N_Unique_Integers_Sum_up_to_Zero {

	/**
	 * @param args
	 */
	public static int[] sumZero(int n) {
        //x=1 -1 2 -2.....
        int temp[]=new int[n];
        int x=1;
        for(int i=0;i<n-1;i+=2){
            temp[i]=x;
            temp[i+1]=-x;
            x++;
        }
        //if n=odd number
        if(n%2!=0)
            temp[n-1]=0;
        return temp;
    }
	
	public static void main(String[] args) {
		int n=5;
		System.out.println("Input: n = "+n);
		System.out.println("Output array is "+Arrays.toString(sumZero(n)));
	}

}
