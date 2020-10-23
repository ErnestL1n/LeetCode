/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.312
public class Burst_Balloons {

	/**
	 * @param args
	 */
	//buttom up method
    public int maxCoinsButtomUp(int[] nums) {
        int[] arr=new int[nums.length+2];
        int n=1;
        for(int num:nums)
            if(num>0)
                arr[n++]=num;
        arr[0]=arr[n++]=1;
        int[][] dp=new int[n][n];
        for(int i=n-1;i>=0;--i)
            for(int j=i+1;j<n;++j)
                for(int k=i+1;k<j;++k)
                    dp[i][j]=Math.max(dp[i][j],
                                dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
        return dp[0][n-1];
    }
    //top down recursive method with memoization
    private int[][] dp=new int[502][502];
    public int maxCoinsTopdown(int[] nums) {
        int[] arr=new int[nums.length+2];
        int n=1;
        for(int num:nums)
            if(num>0)
                arr[n++]=num;
        arr[0]=arr[n++]=1;
        return help(arr,0,n-1);
    }
    private int help(int[] arr,int i,int j){
        if(j-i==1)
            return 0;
        if(dp[i][j]==0){
            for(int k=i+1;k<j;++k)
                dp[i][j]=Math.max(dp[i][j],
                            arr[i]*arr[k]*arr[j]+help(arr,i,k)+help(arr,k,j));
        }
        return dp[i][j];
    }
    
	public static void main(String[] args) {
	}

}
