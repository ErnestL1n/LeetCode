/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1342
public class Number_of_Steps_to_Reduce_a_Number_to_Zero {

	/**
	 * @param args
	 */
	public static int numberOfSteps(int num) {
		int answer=0;
		while(num>0) {
			if(num%2==0)num/=2;
			else num-=1;
			answer++;
		}
		return answer;
	}
	public static void main(String[] args) {
		int num=14;
		System.out.println("Input: num :"+num);
		System.out.println("Output "+numberOfSteps(num));

	}

}
