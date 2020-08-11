/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
public class Minimum_Cost_to_Cut_a_Stick {

	/**
	 * @param args
	 */
    public int minCost(int n, int[] cuts) {
        var c = new ArrayList<Integer>();
        for (int cut : cuts)
            c.add(cut);
        c.addAll(Arrays.asList(0, n));
        Collections.sort(c);
        return dfs(c,0,c.size()-1);
    }
    private int[][] dp=new int[102][102];
    private int dfs(ArrayList<Integer> cuts,int i,int j){
        if(j-i<=1)return 0;
        if(dp[i][j]==0){
            dp[i][j]=Integer.MAX_VALUE;
            for(int k=i+1;k<j;++k)
                dp[i][j]=Math.min(dp[i][j],
                                 cuts.get(j)-cuts.get(i)+dfs(cuts,i,k)+dfs(cuts,k,j));
        }
        return dp[i][j];
    }
	public static void main(String[] args) {
		
	}

}
