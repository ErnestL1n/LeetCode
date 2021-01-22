/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.921
public class Minimum_Add_to_Make_Parentheses_Valid {

	/**
	 * @param args
	 */
	public static int minAddToMakeValid(String S) {
		int answer=0,count=0;
		for(int i=0;i<S.length();i++) {
			if(S.charAt(i)=='(')++count;
			if(S.charAt(i)==')')--count;
			//can't not repair mistakes,just add into answer and restart
			if(S.charAt(i)==')'&&count<=0) {
				answer+=Math.abs(count);
				count=0;
			}
		}
		answer+=count;
		return answer;
	}
	public static void main(String[] args) {
		String S="()))((";
		System.out.println("Given a string S of '(' and ')' parentheses : "+S);
		System.out.println("Minimum number of parentheses we must add to make the resulting string valid is "+minAddToMakeValid(S));

	}
	

}
