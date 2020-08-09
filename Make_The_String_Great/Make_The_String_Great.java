/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1544
public class Make_The_String_Great {

	/**
	 * @param args
	 */
	public static String makeGood(String s) {
		Stack<Character> stack=new Stack<>();
		for(int i=0;i<s.length();++i) {
			if(!stack.isEmpty()&&Math.abs(s.charAt(i)-stack.peek())==32)
				stack.pop();
			else
				stack.push(s.charAt(i));
		}
		char[] res=new char[stack.size()];
		int index=stack.size()-1;
		while(!stack.isEmpty())
			res[index--]=stack.pop();
		return new String(res);
	}
	public static void main(String[] args) {

	}

}
