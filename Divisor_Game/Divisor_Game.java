/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Tricky and amazing question,I give a thumbs up
//Leetcode.1025
//proved by:https://leetcode.com/lee215/

//1.
//If N is even.
//We can choose x = 1.
//The opponent will get N - 1, which is a odd.
//Reduce to the case odd and he will lose.

//2.
//If N is odd,
//2.1 If N = 1, lose directly.
//2.2 We have to choose an odd x.
//The opponent will get N - x, which is a even.
//Reduce to the case even and he will win.

//3.
//So the N will change odd and even alternatively until N = 1.

public class Divisor_Game {

	/**
	 * @param args
	 */
	public static boolean divisorGame(int N) {
		return N%2==0;
	}
	public static void main(String[] args) {
		int N1=56;
		int N2=37;
		System.out.println("N1 is "+N1);
		System.out.println("N1 Return True if and only if Alice wins the game ");
		System.out.println("Return => "+divisorGame(N1));
		System.out.println("N2 is "+N2);
		System.out.println("N2 Return True if and only if Alice wins the game ");
		System.out.println("Return => "+divisorGame(N2));
	}

}
