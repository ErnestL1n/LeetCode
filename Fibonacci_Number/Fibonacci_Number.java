/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.Scanner;
public class Fibonacci_Number {

	/**
	 * @param args
	 */
	public static int Fib(int N) {
		//fib(0)=0  fib(1)=1
		//fib(n)=fib(n-1)+fib(n-2)
		//Iterative Top-Down Approach
		if(N<=1)return N;
		if(N<=2)return 1;
		
		int current=0;
		int prev=1;     //fib(1)
		int preprev=1;  //fib(2)
		
		for(int i=3;i<=N;i++) {
			current=prev+preprev;
			preprev=prev;
			prev=current;
		}
		return current;
	}
	
	public static void main(String[] args) {
		
		Scanner keyboard=new Scanner(System.in);
		System.out.println("Please enter Fibonacci_Number N you want");
		int N=keyboard.nextInt();
		System.out.println("Fibonacci_Number " + N + " is " + Fib(N));


	}

}
