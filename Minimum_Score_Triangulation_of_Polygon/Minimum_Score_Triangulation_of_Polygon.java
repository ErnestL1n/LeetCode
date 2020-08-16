/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1039
public class Minimum_Score_Triangulation_of_Polygon {

	/**
	 * @param args
	 */
	private int[][] dpTopDown=new int[50][50];
	public int minScoreTriangulationTopDown(int[] A) {
        return help(A,0,A.length-1);
    }
	private int help(int[] a,int i,int j) {
		if(j-i<=1)return 0;
		if(dpTopDown[i][j]==0) {
			dpTopDown[i][j]=Integer.MAX_VALUE;
			for(int k=i+1;k<j;++k)
				dpTopDown[i][j]=Math.min(dpTopDown[i][j], a[i]*a[k]*a[j]+help(a,i,k)+help(a,k,j));
		}
		return dpTopDown[i][j];
	}
	
	public int minScoreTriangulationButtomUp(int[] A) {
        int[][] dp=new int[50][50];
        for(int i=A.length-1;i>=0;--i)
            for(int j=i+1;j<A.length;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=Math.min(dp[i][j]==0?Integer.MAX_VALUE:dp[i][j],
                                     dp[i][k]+dp[k][j]+A[i]*A[k]*A[j]);
        return dp[0][A.length-1];
    }
	
	
	public static void main(String[] args) {
		
	}

}
