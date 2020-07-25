/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.46
public class Permutations {

	/**
	 * @param args
	 */
    public static List<List<Integer>> permute(int[] num) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    if (num.length ==0) return ans;
    List<Integer> l0 = new ArrayList<Integer>();
    l0.add(num[0]);
    ans.add(l0);
    for (int i = 1; i< num.length; ++i){
        List<List<Integer>> new_ans = new ArrayList<List<Integer>>(); 
        for (int j = 0; j<=i; ++j){            
           for (List<Integer> l : ans){
        	   List<Integer> new_l = new ArrayList<Integer>(l);
        	   new_l.add(j,num[i]);
        	   new_ans.add(new_l);
           }
        }
        ans = new_ans;
    }
    return ans;
}
	public static void main(String[] args) {
		// TODO 自動產生的方法 Stub

	}

}
