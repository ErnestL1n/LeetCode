/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1252
//I don't think this is an easy question
//It is at least middle level
public class Cells_with_Odd_Values_in_a_Matrix {

	/**
	 * @param args
	 */
	public static int oddCells(int n, int m, int[][] indices) {
		//use xor==> True XOR Y = ~Y
		//       ==>False XOR Y =  Y
		//default value of the boolean array is false
		boolean[] oddRows=new boolean[n],oddColumns=new boolean[m];
		int countRows=0,countColums=0;
		for(int[] index:indices) {
			oddRows[index[0]]^=true;       //if row    idx[0] appears odd times, it will correspond to true.
			oddColumns[index[1]]^=true;    //if column idx[1] appears odd times, it will correspond to true.
		}
		for (boolean row : oddRows)
			countRows += row ? 1 : 0;
        for (boolean column : oddColumns)
        	countColums += column ? 1 : 0;
        // return m * cntRow -cntRow * cntCol + n * cntCol - cntRow * cntCol;;
        return (m - countColums) * countRows + (n - countRows) * countColums;
		
	}
	public static void main(String[] args) {
		int n=2,m=3;
		int[][] indices=new int[][] {{0,1},{1,1}};
		System.out.print("n=" +n+ ", m =" +m +", indices = ");
		for(int i=0;i<indices.length;i++)System.out.print(Arrays.toString(indices[i]));
		System.out.println();
		System.out.print("Number of cells with odd values in the matrix after applying the increment to all indices is :");
		System.out.println(oddCells(n,m,indices));
	}
}
