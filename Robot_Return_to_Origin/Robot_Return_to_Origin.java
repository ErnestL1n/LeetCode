/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.657
public class Robot_Return_to_Origin {

	/**
	 * @param args
	 */
	//use switch case is faster than if/else again and again
	public static boolean judgeCircle(String moves) {
		int x=0,y=0;
		for(char c:moves.toCharArray()) {
			switch(c) {
			case 'U':y++; break;
			case 'D':y--; break;
			case 'R':x++; break;
			case 'L':x--; break;
			}
		}
		return x==0&&y==0;
	}
	public static void main(String[] args) {
		String movement="UDUDUDLRRRUDLL";
		System.out.println("Input string :"+movement);
		System.out.println("If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.");
		System.out.println("the robot returns:"+judgeCircle(movement));

	}

}
