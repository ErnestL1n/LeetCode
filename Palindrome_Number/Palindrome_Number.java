/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.9
public class Palindrome_Number {

	/**
	 * @param args
	 */
	public static boolean isPalindrome(int x) {
		    if (x<0 || (x!=0 && x%10==0)) return false;
		    int rev = 0;
		    while (x>rev){
		    	rev = rev*10 + x%10;
		    	x = x/10;
		    }
		    return (x==rev || x==rev/10);
		}
	public static void main(String[] args) {
		// TODO 自動產生的方法 Stub

	}

}
