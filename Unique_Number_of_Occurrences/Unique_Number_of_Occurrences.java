/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1207
public class Unique_Number_of_Occurrences {

	/**
	 * @param args
	 */
	
	//Great Idea is provided by:https://leetcode.com/rock/
	public static boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int a : arr)
            count.put(a, 1 + count.getOrDefault(a, 0));
        return count.size() == new HashSet<>(count.values()).size();
    }
	
	
	//more concise and readable version is provided by:https://leetcode.com/dontsovigor1/  &  https://leetcode.com/kelvinkkl
	public static boolean uniqueOccurrencesreadable(int[] arr) {
        if (arr == null || arr.length == 0) {
            return true;
        }
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> unique = new HashSet<>();
        for (int val : arr) {
            map.put(val, map.getOrDefault(val, 0) + 1);
        }
        for (int val : map.values()) {
            /*if (unique.contains(val)) {
                return false;
            } else {
                unique.add(val);
            }*/
        	if(!unique.add(val)) return false; // the number represent the occurrences already exists in the hashset.
        }
        return true;
}
	 
	 
	public static void main(String[] args) {
		int[] arr=new int[] {-3,0,1,-3,1,1,1,-3,10,0};
		System.out.println("Given an array of integers "+Arrays.toString(arr));
		System.out.println("returns true if and only if the number of occurrences of each value in the array is unique.");
		System.out.println("=> "+uniqueOccurrencesreadable(arr));
	}

}
