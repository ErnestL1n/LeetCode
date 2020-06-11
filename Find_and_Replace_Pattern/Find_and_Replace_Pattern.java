/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.890
//reference:https://leetcode.com/lee215/
public class Find_and_Replace_Pattern {

	/**
	 * @param args
	 */
	public static List<String> findAndReplacePattern(String[] words, String pattern){
		List<String> answer=new ArrayList<>();
		int[] p=HashConvert(pattern);
		for(String s:words) {
			if(Arrays.equals(p,HashConvert(s)))
				answer.add(s);
		}
		return answer;
	}
	public static int[] HashConvert(String s) {
		HashMap<Character,Integer> map=new HashMap<>();
		int stringlength=s.length();
		int[] converted=new int[stringlength];
		for(int i=0;i<stringlength;i++) {
			//HashMap.size() method of HashMap class is used to get the size of the map
            //which refers to the number of the key-value pair or mappings in the Map
			map.putIfAbsent(s.charAt(i),map.size());
			converted[i]=map.get(s.charAt(i));
		}
		return converted;
	}
	public static void main(String[] args) {
		String[] words= {"abc","deq","mee","aqq","dkd","ccc"};
		String pattern="abb";
		System.out.println("Words are : "+Arrays.toString(words)+" and the given pattern is "+pattern);
		System.out.println("Find And Replace Pattern outputs "+findAndReplacePattern(words,pattern));
	}

}
