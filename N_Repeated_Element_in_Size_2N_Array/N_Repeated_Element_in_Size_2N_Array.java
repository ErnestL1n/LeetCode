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
public class N_Repeated_Element_in_Size_2N_Array {

	/**
	 * @param args
	 */
    public static int repeatedNTimes(int[] A) {
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
		System.out.println("the element repeated N="+sizeN+" times is "+repeatedNTimes(A));

	}

}
