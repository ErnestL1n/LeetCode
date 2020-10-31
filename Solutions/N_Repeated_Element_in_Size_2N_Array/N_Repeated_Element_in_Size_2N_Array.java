/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.961
//provide by https://leetcode.com/lee215/
public class N_Repeated_Element_in_Size_2N_Array {

	/**
	 * @param args
	 */
	
	//Solution 1:Use array or set and return seen number at once.
	//O(N) time, O(N) space
    public static int repeatedNTimesMethod1(int[] A) {
        int[] count = new int[10000];
        for (int a : A)
            if (count[a]++ == 1)
                return a;
        return -1;
    }
    
    //Solution 2
    //Check if A[i] == A[i - 1] or A[i] == A[i - 2]
    //If so, we return A[i]
    //If not, it must be [x, x, y, z] or [x, y, z, x].
    //We return A[0] for the cases that we miss.
    //O(N) time O(1) space
    
    public static int repeatedNTimes(int[] A) {
        for (int i = 2; i < A.length; ++i)
            if (A[i] == A[i - 1] || A[i] == A[i - 2])
                return A[i];
        return A[0];
    }
    
    
    //Solution 3
    //Instead of compare from left to right,
    //we can compare in random order.
    //Random pick two numbers.
    //Return if same.
    //50% to get the right number.
    //Each turn, 25% to get two right numbers.
    //Return the result in average 4 turns.
    //Time complexity amortized O(4), space O(1)
    
    
    public static int repeatedNTimes3ForFun(int[] A) {
        int i = 0, j = 0, n = A.length;
        while (i == j || A[i] != A[j]) {
            i = (int)(Math.random() * n);
            j = (int)(Math.random() * n);
        }
        return A[i];
    }
    
    
	public static void main(String[] args) {
		int[] A=new int[] {1,2,3,3};
		int sizeN=A.length/2;
		System.out.println("2N size array is : "+Arrays.toString(A));
		System.out.println("the element repeated N="+sizeN+" times is "+repeatedNTimes3ForFun(A));

	}

}
