/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.Scanner;
public class Number_Complement {

	/**
	 * @param args
	 */
	//The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
	//You could assume no leading zero bit in the integer¡¦s binary representation.
	public static int complement(int num) {
		
		//count bits with total
		int n=num;
		int total=1;
		while(n>1) {	
			n>>=1;
		   total=(total<<1)|1;	 
		}
		//a XOR 1= ~a
		return total^num;
		
	}
	
	public static void main(String[] args) {
		
		
		System.out.println("Enter the number to get its complement");
		Scanner keyboard=new Scanner(System.in);
		int N=keyboard.nextInt();
		int comp=complement(N);
		System.out.println("The binary representation of "+N+" is "
				+ Integer.toBinaryString(N) +" (no leading zero bits), and its complement is (Leading zeros)"
				+Integer.toBinaryString(comp)+" which is "+comp);
	}

}
