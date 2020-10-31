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
	/*
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
	*/
	
	//much brilliant solution
	//  n=6
	//  i =0,1,2,3,4,5
	//a[i]=-5,-3,-1,1,3,5
	//=>a[i]=i*2-n+1
	//n==odd is OK
	
	
	public static int[] sumZero(int n) {
		int[] a=new int[n];
		for(int i=0;i<n;i++)a[i]=i*2-n+1;
		return a;
	}
	
	public static void main(String[] args) {
		int n=5;
		System.out.println("Given an integer n :"+n);
		System.out.println("return any array containing n unique integers such that they add up to 0 :"+Arrays.toString(sumZero(n)));
	}

}

