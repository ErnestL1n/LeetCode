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

	/**
	 * @param args
	 */
	
	
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
		System.out.println("Input num "+num);
		System.out.println("Ouput num becomes "+max69(num));

	}

}
