/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1314
public class Matrix_Block_Sum {

	/**
	 * @param args
	 */
	//Thanks to https://leetcode.com/hiepit/ & https://leetcode.com/rock/
	public static int[][] matrixBlockSum(int[][] mat, int K){
		int row=mat.length,column=mat[0].length;
		int[][] rangesum=new int[row+1][column+1];
		//rangesum[i][j] is sum of all elements from rectangle (0,0,i,j) as left, top, right, bottom corresponding
		for(int r=1;r<rangesum.length;++r)
			for(int c=1;c<rangesum[0].length;++c)
				rangesum[r][c]=mat[r-1][c-1]+rangesum[r-1][c]+rangesum[r][c-1]-rangesum[r-1][c-1];
		int[][] res=new int[row][column];
		for(int r=0;r<row;++r)
			for(int c=0;c<column;++c) {
				// Since "rangesum" start with 1 so we need to increase r1, c1, r2, c2 by 1
				int r_lo=Math.max(0, r-K)+1,c_lo=Math.max(0, c-K)+1;
				int r_hi=Math.min(row, r+K+1),c_hi=Math.min(column, c+K+1);
				res[r][c]=rangesum[r_hi][c_hi]-rangesum[r_lo-1][c_hi]-rangesum[r_hi][c_lo-1]+rangesum[r_lo-1][c_lo-1];
				}
		return res;
	}
	
	public static void main(String[] args) {
		int[][] mat= {{1,2,3},{4,5,6},{7,8,9}};
		int K=1;
		System.out.println("Given a m * n matrix mat ");
		for(int r=0;r<mat.length;++r)
			System.out.println(Arrays.toString(mat[r]));
		System.out.println("and an integer K="+K);
		System.out.println("\nreturn a matrix answer where each answer[i][j] is the sum of all elements");
		System.out.println("mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.");
		
		System.out.println("Matrix Block Sum => ");
		mat=matrixBlockSum(mat,K);
		for(int r=0;r<mat.length;++r)
			System.out.println(Arrays.toString(mat[r]));
	}

}
