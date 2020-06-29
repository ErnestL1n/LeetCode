/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1323
public class Maximum_69_Number {
	
	
	//constraint:1 <= num <= 10^4
	//num's digits are 6 or 9.
	public static int max69(int num) {
		int maxdigit=0;
		int currdigit=1;
		int n=num;
		while(n>0) {
			if(n%10==6)maxdigit=currdigit;
			currdigit*=10;
			n/=10;
		}
		return num+3*maxdigit;
		
	}
	public static void main(String[] args) {
		int num=66666996;
		System.out.println("Given a positive integer num :"+num+" consisting only of digits 6 and 9 ");
		System.out.println("Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6) :"+max69(num));

	}

}