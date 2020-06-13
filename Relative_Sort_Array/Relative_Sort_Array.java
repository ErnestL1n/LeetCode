/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1122
public class Relative_Sort_Array {

	/**
	 * @param args
	 */
	public static int[] relativeSortArray(int[] arr1, int[] arr2) {
		//Constraints
        //arr1.length, arr2.length <= 1000
		int[] count=new int[1001];
        int recentlycount=0;
        for(int i:arr1)count[i]++;
        for(int i:arr2){
            while(count[i]-->0)
                arr1[recentlycount++]=i;
        }
        for(int i=0;i<count.length;i++)
            while(count[i]-->0)arr1[recentlycount++]=i;
        return arr1;
	}
	public static void main(String[] args) {
		int[] arr1=new int[] {2,3,1,3,2,4,6,7,9,2,19};
		int[] arr2=new int[] {2,1,4,3,9,6};
		System.out.println("arr1 ="+Arrays.toString(arr1)+" , arr2 = "+Arrays.toString(arr2));
		System.out.println("Relative Sort Array "+Arrays.toString(relativeSortArray(arr1,arr2)));
	}

}
