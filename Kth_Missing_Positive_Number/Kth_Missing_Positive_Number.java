/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.5468
public class Kth_Missing_Positive_Number {

	/**
	 * @param args
	 */
    public int findKthPositive(int[] arr, int k) {
        HashSet<Integer> set=new HashSet<>();
        int res=0;
        for(int i=0;i<arr.length;++i){
            set.add(arr[i]);
        }
        int count=0;
        for(int i=1;i<=2000;++i){
            if(!set.contains(i))
                ++count;
            if(count==k){
                res=i;
                break;
            }
        }
        return res;
    }
	public static void main(String[] args) {

	}

}
