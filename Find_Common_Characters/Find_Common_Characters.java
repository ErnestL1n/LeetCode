/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1002
public class Find_Common_Characters {

	/**
	 * @param args
	 */
	//provided by:https://leetcode.com/sntz95/
	//HashMap
	//45ms
	public static List<String> commonChars(String[] A) {
        List<String> res = new ArrayList<String>(); 
        if(A == null || A.length == 0) return res; 
        Map<Character,Integer> init=new HashMap<>();
        for(int i=0;i<A[0].length();i++){
            init.put(A[0].charAt(i),1+init.getOrDefault(A[0].charAt(i),0));
        }
        for(int i=1;i<A.length;i++){
            HashMap<Character,Integer> temp=new HashMap<>();
            for(int j = 0; j < A[i].length(); j++){
            char curr = A[i].charAt(j); 
            if(init.containsKey(curr)) temp.put(curr, Math.min(init.get(curr), temp.getOrDefault(curr, 0)+1)); 
        }
        init = temp;
        }
        
       for(char c : init.keySet()){
        for(int i = 0; i < init.get(c); i++) res.add(c + ""); 
       }
        return res;
    }
	public static void main(String[] args) {
		String[] A=new String[] {"bella","label","roller"};
		System.out.println("Given an array A of strings made only from lowercase letters");
		System.out.println(Arrays.toString(A));
		System.out.println("return a list of all characters that show up in all strings within the list (including duplicates)");
		System.out.println(commonChars(A));
	}

}
