/**
 * 
 */
package github.com.ErnestL1n;
import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.542
public class Zero_One_Matrix {

	/**
	 * @param args
	 */
	public static int[][] updateMatrix(int[][] matrix) {   
        int rows = matrix.length;
        if (rows == 0)
            return matrix;
        
        int cols = matrix[0].length;
        
        int[][] moves = new int[][] {
            {1,0}, {0,1}
        };
        int[][] dp = new int[matrix.length][matrix[0].length];
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    dp[row][col] = 0;
                } else {
                    // If you take integer max then it will have overflow issues
                    dp[row][col] = rows * cols;
                    for (int[] move : moves) {
                        int nextRow = row - move[0];
                        int nextCol = col - move[1];
                        
                        if (isValid(nextRow, nextCol, rows, cols))
                            dp[row][col] = Math.min(dp[row][col], dp[nextRow][nextCol] + 1);
                    }
                    
                }
                    
            }
        }
        
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                if (matrix[row][col]==0){
                    dp[row][col] = 0;
                } else {
                    for (int[] move : moves) {
                        int nextRow = row + move[0];
                        int nextCol = col + move[1];

                        if (isValid(nextRow, nextCol, rows, cols))
                            dp[row][col] = Math.min(dp[row][col], dp[nextRow][nextCol] + 1);
                    }
                }
            }
        }
        return dp;
    }
    
    private static boolean isValid(int nextRow, int nextCol, int rows, int cols) {
        return (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols);
    }
	public static void main(String[] args) {
		int[][] matrix=new int[][] {{0,0,0}, {0,1,0}, {1,1,1}};
		System.out.println("Input array is :");
		System.out.print("[");
		for(int i=0;i<matrix.length-1;i++)
			System.out.println(Arrays.toString(matrix[i])+",");
		System.out.print(Arrays.toString(matrix[matrix.length-1]));
		System.out.println("]");
		int[][] zero_one_array=updateMatrix(matrix);
		System.out.println("Output array is :");
		System.out.print("[");
		for(int i=0;i<zero_one_array.length-1;i++)
			System.out.println(Arrays.toString(zero_one_array[i])+",");
		System.out.print(Arrays.toString(zero_one_array[zero_one_array.length-1]));
		System.out.println("]");
		}


}
