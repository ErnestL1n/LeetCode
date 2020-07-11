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
	
	
	//trick implementation is provided by:https://leetcode.com/coder206/
	private static int xorOperationB(int n, int start)
    {
        if (n % 2 == 0)
            return (n / 2) & 1;
        else
            return ((n / 2) & 1) ^ (start + n - 1);
    }
    private static int xorOperationA(int n, int start)
    {
        if ((start & 1)==1)
            return (start - 1) ^ xorOperationB(n + 1, start - 1);
        else
            return xorOperationB(n, start);
    }    
    public static int xorOperationTrick(int n, int start)
    {
        int ret = 2 * xorOperationA(n, start / 2);
        if ((n & start & 1)==1) ret++;
        return ret;
    }
    
	
	public static void main(String[] args) {
		int n=4,start=3;
		System.out.println("Given an integer n "+n+" and an integer start."+start);
		System.out.println("Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.");
		System.out.println("Return the bitwise XOR of all elements of nums.");
		System.out.println("=> "+xorOperationTrick(n,start));
	}

}
