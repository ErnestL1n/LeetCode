/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Weekly Contest 199 
//Leetcode.1528
public class Shuffle_String {

	/**
	 * @param args
	 */
	public String restoreString(String s, int[] indices) {
		char[] c=new char[s.length()];
		for(int i=0;i<s.length();++i)
			c[indices[i]]=s.charAt(i);
		return new String(c);
	}
	public static void main(String[] args) {

	}

}
