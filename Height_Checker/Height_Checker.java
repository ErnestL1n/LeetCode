/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1051
//Unclear defined problem
public class Height_Checker {

	/**
	 * @param args
	 */
	//using counting sort
    public static int heightChecker(int[] heights) {
        int[] count=new int[101];
        //counting sort
        for(int h:heights)
            count[h]++;
        int res=0,currcount=0;
        for(int i=0;i<heights.length;i++){
            while(count[currcount]==0)
                ++currcount;
            if(currcount!=heights[i])
                res++;
            count[currcount]--;
        }
        return res;
    }
	public static void main(String[] args) {
		int[] heights=new int[] {1,1,4,2,1,3};
		System.out.println("heights array is : "+Arrays.toString(heights));
		System.out.println("the minimum number of students that must move in order "
				+ "for all students to be standing in non-decreasing order of height is "+heightChecker(heights));
	}

}
