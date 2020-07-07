/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1389
public class Create_Target_Array_in_the_Given_Order {

	/**
	 * @param args
	 */
    public static int[] createTargetArray(int[] nums, int[] index) {
        List<Integer> list=new ArrayList();
        for(int i=0;i<nums.length;i++) {
            list.add(index[i],nums[i]);
            System.out.println(nums[i]+"                "+index[i]+"              "+list);
        }
        int[] res=new int[list.size()];
        for(int i=0;i<list.size();i++)
            res[i]=list.get(i);
        return res;
    }
    
    //provided by https://leetcode.com/heshan1234/
    //O(nlogn) based on "smaller elements after self"
    public static int[] createTargetArrayEX(int[] nums, int[] index) {
        int n = nums.length;
        int[] a = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = i;
        }
        helper(a, 0, n, index, new int[n]);
        int[] result = new int[n];
        for(int i = 0; i < n; ++i) {
            result[index[i]] = nums[i];
        }
        return result;
    }
    
    static void helper(int[] a, int i, int j, int[] index, int[] tmp) {
        if (j - i <= 1) {
            return;
        }
        int k = (i + j) >>> 1;
        helper(a, i, k, index, tmp);
        helper(a, k, j, index, tmp);
        int x = i;
        int y = k;
        int z = 0;
        int count = 0;
        while(x < k && y < j) {
            while(y < j && index[a[y]] <= index[a[x]] + count) {
                ++count;
                tmp[z++] = a[y++];
            }
            index[a[x]] += count;
            tmp[z++] = a[x++];
        }
        while(x < k) {
            index[a[x]] += count;
            tmp[z++] = a[x++];
        }
        while(y < j) {
            tmp[z++] = a[y++];
        }
        for(int p = i, q = 0; p < j; ++p, ++q) {
            a[p] = tmp[q];
        }
    }
    
    
	public static void main(String[] args) {
		int[] nums=new int[] {1,2,3,4,0};
		int[] index=new int[] {0,1,2,3,0};
		System.out.println("nums           index           target  ");		
		createTargetArray(nums,index);
	}

}
