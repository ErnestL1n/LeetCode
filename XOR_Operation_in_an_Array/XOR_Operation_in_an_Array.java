/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1486
public class XOR_Operation_in_an_Array {

	/**
	 * @param args
	 */
	public static int xorOperation(int n, int start) {
        int res=0;
        for(int i=0;i<n;++i)
            res^=(start+2*i);
        return res;
    }
	
	public static void main(String[] args) {
		int n=4,start=3;
		System.out.println("Given an integer n "+n+" and an integer start."+start);
		System.out.println("Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.");
		System.out.println("Return the bitwise XOR of all elements of nums.");
		System.out.println(" => "+xorOperation(n,start));
	}

}
