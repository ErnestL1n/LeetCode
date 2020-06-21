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
	        int count=0,leftcount=0,rightcount=0;
	        for(int i=0;i<s.length();i++){
	            if(s.charAt(i)=='R')
	                rightcount++;
	            if(s.charAt(i)=='L')
	                leftcount++;
	            if(rightcount!=0&&rightcount==leftcount)
	                count++;
	        }
	        return count;
	    }
	
	
	public static void main(String[] args) {
		String s="RLRRRLLRLL";
		System.out.println("Given a balanced string : "+s+ " ,split it in the maximum amount of balanced strings");
		System.out.println("the maximum amount of splitted balanced strings is "+balancedStringSplit(s));
	}

}
