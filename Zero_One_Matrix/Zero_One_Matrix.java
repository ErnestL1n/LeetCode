/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;

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
	
	//BFS approach
    public static int[][] updateMatrixQueue(int[][] matrix) {
        Queue<int[]> queue = new LinkedList<>();
        int m = matrix.length, n = matrix[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
        }
        int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int i = 0; i < 4; i++) {
                int row = cur[0] + dir[i][0];
                int col = cur[1] + dir[i][1];
                if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col]) {
                    continue;
                }
                visited[row][col] = true;
                matrix[row][col] = matrix[cur[0]][cur[1]] + 1;
                queue.offer(new int[]{row, col});
            }
        }
        return matrix;
    }
    
    private static boolean isValid(int nextRow, int nextCol, int rows, int cols) {
        return (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols);
    }
	public static void main(String[] args) {
		int[][] matrix=new int[][] {{0,0,0}, {0,1,0}, {1,1,1}};
		System.out.println("Input array is :");
		for(int i=0;i<matrix.length-1;i++)
			System.out.println(Arrays.toString(matrix[i])+",");
		System.out.print(Arrays.toString(matrix[matrix.length-1]));
		int[][] zero_one_array=updateMatrix(matrix);
		System.out.println("\nOutput array is :");
		for(int i=0;i<zero_one_array.length-1;i++)
			System.out.println(Arrays.toString(zero_one_array[i])+",");
		System.out.print(Arrays.toString(zero_one_array[zero_one_array.length-1]));
		}


}
