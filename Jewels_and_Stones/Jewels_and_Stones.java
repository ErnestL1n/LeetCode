/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
import java.util.*;

//Leetcode.771
public class Jewels_and_Stones {

	/**
	 * @param args
	 */
	public static int numJewelsInStones(String J, String S) {
        Set<Character> JewSet=new HashSet<>();
        
        for(int j=0;j<J.length();j++)
            JewSet.add(J.charAt(j));
        
        int output=0;
        
        for(int i=0;i<S.length();i++){
            if(JewSet.contains(S.charAt(i)))
                output++;
        }
        
        return output;
    }
	public static void main(String[] args) {
		
		String J="aA",S="aAAbbbb";
		System.out.println("J is ["+J+"],S is ["+S+"]");
		System.out.println("Number of Jewels In Stones is:"+numJewelsInStones(J,S));

	}

}
