/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.905
public class Sort_Array_By_Parity {

	/**
	 * @param args
	 */
	/*
	public static int[] sortArrayByParity(int[] A) {
		straight forward
		int[] temp=new int[A.length];
		int evencount=0,oddstart=0;
		for(int i=0;i<A.length;i++) 
			if(A[i]%2==0)
				temp[evencount++]=A[i];
		oddstart+=evencount;
		for(int i=0;i<A.length;i++)
			if(A[i]%2!=0)
				temp[oddstart++]=A[i];
		return temp;
		
	}
	*/
	
	//may use much memory space,provided by https://leetcode.com/lee215/
	public static int[] sortArrayByParity(int[] A) {
		for(int i=0,j=0;j<A.length;j++) {
			if(A[j]%2==0) {
				int temp=A[i];
				A[i++]=A[j];
				A[j]=temp;
			}
		}
		return A;
	}
	
	public static void main(String[] args) {
		int[] A=new int[]{3,1,2,4};
		System.out.println("Given an array A of non-negative integers "+ Arrays.toString(A));

		System.out.println("You may return any answer array that satisfies this condition: all the even elements of A, followed by all the odd elements of A.");
		
		System.out.println("Given an array A of non-negative integers "+ Arrays.toString(sortArrayByParity(A)));
	}
}
