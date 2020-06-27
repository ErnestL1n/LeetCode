/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.Scanner;
//Leetcode.509
public class Fibonacci_Number {

	/**
	 * @param args
	 */
	
	//Fib(0)=0,Fib(1)=1,if(N>=2),Fib(N)=Fib(N-1)+Fib(N-2)
	
	
	//method 1:recursive approach
	
	public static int Fib1(int N) {
		if(N<=1)return N;
		return Fib1(N-1)+Fib1(N-2);
	}
	
	
	//method 2:Bottom-Up Approach using Memoization
	
	public static int Fib2(int N) {
		if(N<=1)return N;
		return memorize2(N);
	}
	private static int memorize2(int N) {
		int[] memo2=new int[N+1];
		memo2[0]=0;
		memo2[1]=1;
		for(int i=2;i<=N;i++)
			memo2[i]=memo2[i-1]+memo2[i-2];
		return memo2[N];
	}
	
	//method 3:Top-Down Approach using Memoization
	
	private static Integer[] memo3 = new Integer[31];
	
	public static int Fib3(int N) {
		if(N<=1)return N;
		memo3[0]=0;
		memo3[1]=1;
		return memorize3(N);
	}
	private static int memorize3(int N) {
		if(memo3[N]!=null)return memo3[N];
		memo3[N]=memorize3(N-1)+memorize3(N-2);
		return memorize3(N);
	}
	
	//method 4: Iterative Top-Down Approach
	
	public static int Fib4(int N) {
        if(N<=1)return N;
        if(N==2)return 1;
        int current=0;
        int prev1=1;
        int prev2=1;
        for(int i=3;i<=N;i++){
            current=prev1+prev2;
            prev2=prev1;
            prev1=current;
        }
        return current;
    }
	
	public static void main(String[] args) {
		Scanner keyboard=new Scanner(System.in);
		System.out.println("Please enter Fibonacci_Number N you want");
		int N=keyboard.nextInt();
		System.out.println("Fibonacci_Number " + N + " is " + Fib4(N));
	}

}
