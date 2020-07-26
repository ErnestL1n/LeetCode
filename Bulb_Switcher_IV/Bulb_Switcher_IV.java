/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Weekly Contest 199 
//Leetcode.1529
public class Bulb_Switcher_IV {

	/**
	 * @param args
	 */
	public static int minFlips(String target) {
		int res=0;
		char[] tc=target.toCharArray();
		char c='0';
		for(char ch:tc) {
			if(ch!=c) {
				++res;
				c=ch;
			}
		}
		return res;
	}
	public static void main(String[] args) {
	}

}
