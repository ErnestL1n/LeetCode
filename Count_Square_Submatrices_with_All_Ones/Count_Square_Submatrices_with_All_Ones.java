/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1277
public class Count_Square_Submatrices_with_All_Ones {

	/**
	 * @param args
	 */
    public int countSquares(int[][] matrix) {
        int answer=0;
        for (int i = 0; i < matrix.length; ++i) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (matrix[i][j] > 0 && i > 0 && j > 0) {
                    matrix[i][j] = Math.min(matrix[i - 1][j-1],Math.min(matrix[i][j-1], matrix[i-1][j]))+1;
                }
                answer += matrix[i][j];
            }
        }
        return answer;
    }
	public static void main(String[] args) {
		

	}

}
