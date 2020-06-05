/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1281
public class Subtract_Product_Sum_of_Digits_of_an_Integer {

	/**
	 * @param args
	 */
	//constraint
	public static int subProSum(int n) {
		int product=1;
		int sum=0;
		while(n>0) {
			product*=n%10;
			sum+=n%10;
			n/=10;
		}
		return product-sum;
	}
	
	public static void main(String[] args) {
		int num=1000;
		System.out.println("Input : n = "+num);
		System.out.println("Output: = "+subProSum(num));
	}

}
