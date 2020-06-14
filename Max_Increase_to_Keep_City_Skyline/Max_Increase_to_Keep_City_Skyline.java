/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.807
public class Max_Increase_to_Keep_City_Skyline {

	/**
	 * @param args
	 */
	public static int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] skylineHorizontal=new int[grid.length];
        int[] skylineVertical  =new int[grid[0].length];
        for(int i=0;i<grid.length;i++)
            for(int j=0;j<grid[0].length;j++){
                skylineHorizontal[i]=Math.max(skylineHorizontal[i],grid[i][j]);
                skylineVertical[j]  =Math.max(skylineVertical[j],grid[i][j]);
            }
        int addHeight=0;
           for(int i=0;i<grid.length;i++)
            for(int j=0;j<grid[0].length;j++)
                addHeight+=Math.min(skylineHorizontal[i],skylineVertical[j])-grid[i][j];
         return addHeight;
    }
	public static void main(String[] args) {
		int[][] grid = new int[][] {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
		System.out.println("Heights of all buildings located there are ");
		for(int i=0;i<grid.length;i++)
			System.out.println(Arrays.toString(grid[i]));
		System.out.println("Maximum total sum that the height of the buildings can be increased is "+maxIncreaseKeepingSkyline(grid));
		
	}

}
