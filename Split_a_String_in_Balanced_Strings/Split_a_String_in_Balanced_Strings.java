/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1221
public class Split_a_String_in_Balanced_Strings {

	/**
	 * @param args
	 */
	//constraint:
	//1 <= s.length <= 1000
	//s[i] = 'L' or 'R'
	public static int balancedStringSplit(String s) {
        int count=0,ln=0,rn=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='R')
                rn++;
            if(s.charAt(i)=='L')
                ln++;
            if(ln!=0&&rn==ln)
                count++;
        }
        return count;
    }
	
	
	public static void main(String[] args) {
		String s="RLRRRLLRLL";
		System.out.println("Input: s = "+s);
		System.out.println("Output: "+balancedStringSplit(s));
	}

}
