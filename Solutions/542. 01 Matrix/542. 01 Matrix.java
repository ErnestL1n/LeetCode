
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
	
	//Time Limit Exceeded on leetcode compiler
	public static int[][] updateMatrixBruteForce(int[][] matrix){
		int row=matrix.length,column=matrix[0].length;
        if(matrix==null||row==0||column==0) return matrix;
        int[][] res=new int[row][column];
        for(int[] rows:res)
            Arrays.fill(rows,Integer.MAX_VALUE);
        for(int i=0;i<row;++i)
            for(int j=0;j<column;++j){
                if(matrix[i][j]==0)
                    res[i][j]=0;
                else{
                    for(int k=0;k<row;++k)
                        for(int l=0;l<column;++l)
                            if(matrix[k][l]==0){
                                int temp=Math.abs(i-k)+Math.abs(j-l);
                                res[i][j]=Math.min(temp,res[i][j]);
                            }
                }
            }
        return res;
	}
	
	
	
	
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
    
    public static int[][] updateMatrixDP(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return matrix;
        }
        int[][] dis = new int[matrix.length][matrix[0].length];
        int range = matrix.length * matrix[0].length;
        
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                } else {
                    int upCell = (i > 0) ? dis[i - 1][j] : range;
                    int leftCell = (j > 0) ? dis[i][j - 1] : range;
                    dis[i][j] = Math.min(upCell, leftCell) + 1;
                }
            }
        }
        
        for (int i = matrix.length - 1; i >= 0; i--) {
            for (int j = matrix[0].length - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                } else {
                    int downCell = (i < matrix.length - 1) ? dis[i + 1][j] : range;
                    int rightCell = (j < matrix[0].length - 1) ? dis[i][j + 1] : range;
                    dis[i][j] = Math.min(Math.min(downCell, rightCell) + 1, dis[i][j]);
                }
            }
        }
        
        return dis;
    }
    
  
    public int[][] updateMatrixDP2(int[][] matrix) {
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) {
                Arrays.fill(dp[i], 10000);
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) dp[i][j] = 0;
                    else {
                        if (i > 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + 1);
                        if (j > 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i < m - 1) dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] + 1);
                    if (j < n - 1) dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] + 1);
                }
            }

            return dp;
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
