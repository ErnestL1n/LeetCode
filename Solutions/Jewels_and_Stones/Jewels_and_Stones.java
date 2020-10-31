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
        
        for(int i=0;i<J.length();i++)
            JewSet.add(J.charAt(i));
        
        int output=0;
        
        for(int i=0;i<S.length();i++){
            if(JewSet.contains(S.charAt(i)))
                output++;
        }
        
        return output;
    }
	public static void main(String[] args) {
		
		String J="aA",S="aAAbbbb";
		System.out.println("Jewel set is ["+J+"],Stone set is ["+S+"]");
		System.out.println("Number of Jewels In Stones set is :"+numJewelsInStones(J,S));

	}

}