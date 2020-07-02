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
    public static int repeatedNTimesMethod1(int[] A) {
        int[] count = new int[10000];
        for (int a : A)
            if (count[a]++ == 1)
                return a;
        return -1;
    }
    public static int repeatedNTimesMethod2(int[] A) {
        int i = 0, j = 0, n = A.length;
        while (i == j || A[i] != A[j]) {
            i = (int)(Math.random() * n);
            j = (int)(Math.random() * n);
        }
        return A[i];
    }
    
    
    public int repeatedNTimes3ForFun(int[] A) {
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
		System.out.println("the element repeated N="+sizeN+" times is "+repeatedNTimesMethod1(A));

	}

}
