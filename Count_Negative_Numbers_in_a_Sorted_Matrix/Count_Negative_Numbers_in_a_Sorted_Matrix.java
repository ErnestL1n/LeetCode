/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */

//Leetcode.1351
//reference:https://leetcode.com/gthor10/
public class Count_Negative_Numbers_in_a_Sorted_Matrix {

	/**
	 * @param args
	 */
	public static int countNegatives(int[][] grid) {
		int count=0;
		int left,right;
		for(int i=0;i<grid.length;i++) {
			//case 1:add whole row
			if(grid[i][0]<0) {
				count+=grid[i].length;
				//continue for loop
				continue;
			}
			//case 2:this row is useless
			if(grid[i][grid[i].length-1]>0)
				continue;
			left=0;
			right=grid[i].length-1;
			//case 3:binary search number<0 in the left and right interval
			while(left<=right) {
				int mid=(left+right)/2;
				if(grid[i][mid]<0)right=mid-1;
				else
					left=mid+1;
			}
			count+=grid[i].length-left;
			right=left;
		}
		return count;
	}
	public static void main(String[] args) {
		int[][] grid = new int[][] {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
		System.out.println("grid is given as : ");
		for(int i=0;i<grid.length;i++)
			System.out.println(Arrays.toString(grid[i]));
		System.out.println("Number of negative numbers in grid is "+countNegatives(grid));
	}

}
