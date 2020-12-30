/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.221
public class Maximal_Square {

	/**
	 * @param args
	 */
	
	public static int maximalSquare(char[][] matrix) {
		if(matrix==null||matrix.length==0||matrix[0].length==0)return 0;
		int row=matrix.length;
		int column=matrix[0].length;
		int[][] temp=new int[row][column];
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				temp[i][j]=Character.getNumericValue(matrix[i][j]);
		int edge=0;
		for(int i=0;i<row;i++) {
			for(int j=0;j<column;j++) {
				if(i>0 && j>0 && temp[i][j]>0)
					temp[i][j]=Math.min(temp[i-1][j-1], Math.min(temp[i][j-1], temp[i-1][j]))+1;
				edge=Math.max(edge, temp[i][j]);
			}
		}
		return edge*edge;
	}
	public static void main(String[] args) {
		char[][] matrix=new char[][] {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
		System.out.println("Given a 2D binary matrix filled with 0's and 1's :");
		for(int i=0;i<matrix.length;i++)
			System.out.println(Arrays.toString(matrix[i]));
		System.out.println("the largest square containing only 1's is ");
		System.out.println(maximalSquare(matrix));
	}

}
