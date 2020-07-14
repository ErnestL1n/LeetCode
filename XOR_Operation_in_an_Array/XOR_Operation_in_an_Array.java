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
	 
	/* xorOperationTrick =>
	 * We have sequence start, start+2, ..., start+2*(n-1).
	 * Last bit in all numbers is the same. 
	 * If it is 0 or n is even then last bit of the result is 0 too, otherwise it is 1.
	 * 
	 * We shift all numbers by 1 to the right and get the new sequence (start/2), (start/2)+1, ..., (start/2)+(n-1).
	 * All we have to do is to calculate xor of all these numbers and append the last bit.
	 * 
	 * xorOperationA =>
	 * So we have to calculate xor of the sequence (for new start value that equals old start devided by 2) start, start+1, ..., start+(n-1).
	 * It is obvious that (2a)^(2a+1) = 1.
	 * Thus it is very handy to make start even. If start is even we have nothing to do, 
	 * but if it is odd we calculate (start-1) ^ (start-1)^start^(start+1)^...^(start+(n-1)).
	 * 
	 * xorOperationB =>
	 * Now we have to calculate xor of the sequence (for some new start value)
	 * start, start+1, ..., start+(n-1) and start is even!!!!!. Every consecutive pair gives 1 and we have n/2 pairs. 
	 * All (n/2) pairs contribute 1 to the result and we have to take into account the last unpaired number if it exists.*/
	
	//find pairs
	private static int xorOperationB(int n, int start)
    {
        if (n % 2 == 0)
            return (n / 2) & 1;
        //take into account the last unpaired number if it exists,last one which is start+n-1
        else
            return ((n / 2) & 1) ^ (start + n - 1);
    }
	
	//make new start value to be even,making it handy
	//(start-1) ^ (start-1) where is 0 (trick is here)  ^  start ^ (start+1)^...^(start+(n-1))  => becomes itself
    private static int xorOperationA(int n, int start)
    {
    	//odd,making it to be even 
        if ((start & 1)==1)
            return (start - 1) ^ xorOperationB(n + 1, start - 1);
        else
            return xorOperationB(n, start);
    }    
    
    public static int xorOperationTrick(int n, int start)
    {
    	
        int ret = 2 * xorOperationA(n, start / 2);
        //Last bit in all numbers is the same.
        //If it is "0 or n is even" then last bit of the result is 0 too, otherwise it is 1.
        //All (n/2) pairs contribute 1 to the result and we have to take into account the last unpaired number if it exists.
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