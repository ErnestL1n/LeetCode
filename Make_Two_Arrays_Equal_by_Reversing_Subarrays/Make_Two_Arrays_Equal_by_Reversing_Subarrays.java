/**
 * 
 */
package github.com.ErnestL1n;


import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1460
public class Make_Two_Arrays_Equal_by_Reversing_Subarrays {

	/**
	 * @param args
	 */
	//constraints:
	//target.length == arr.length
	//1 <= target.length <= 1000
	// <= target[i] <= 1000
	//1 <= arr[i] <= 1000
	
    public static boolean canBeEqual(int[] target, int[] arr) {
        
        int[] record=new int[1001];
        
        for(int i=0;i<target.length;i++){
            record[target[i]]++;
            record[arr[i]]--;
        }
        for(int i=0;i<1001;i++){
            if(record[i]!=0)
                return false;
        }
        return true;
    }
    public static boolean canBeEqualSimplify(int[] target, int[] arr) {
        int[] record=new int[1001];
        for(int a:arr)++record[a];
        for(int t:target)
        	if(--record[t]<0)
        		return false;
        return true;
    }
    
    
    
	public static void main(String[] args) {
		int[] target=new int[] {1,2,3,4};
		int[] arr=new int[] {2,4,1,3};
		System.out.println("Given two integer arrays of equal length target : "+Arrays.toString(target)+" , arr : "+Arrays.toString(arr));
		System.out.println("Return True if you can make arr equal to target , or False otherwise : "+canBeEqual(target,arr));
	}

}
