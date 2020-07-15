/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.338
public class Counting_Bits {

	/**
	 * @param args
	 */
	
	public static int[] countBits(int num) {
        int[] res=new int[num+1];
        for(int i=1;i<=num;++i)
            res[i]=res[i>>1]+(i&1);
        return res;
    }
	
	public static int[] countBitsDP(int num) {
	    int result[] = new int[num + 1];
	    int offset = 1;
	    for (int index = 1; index < num + 1; ++index){
	        if (offset * 2 == index){
	            offset *= 2;
	        }
	        result[index] = result[index - offset] + 1;
	    }
	    return result;
	}
	
	public static void main(String[] args) {
		int num=5;
		System.out.println("Given a non negative integer number num : "+num);
		System.out.println("For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's "
				+ "in their binary representation and return them as an array.");
		System.out.println(Arrays.toString(countBitsDP(num)));

	}

}
