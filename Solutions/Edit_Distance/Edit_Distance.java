/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.72
public class Edit_Distance {

	/**
	 * @param args
	 */
    public static int minDistance(String word1, String word2) {
        //Goal : convert word1 to word2
        int length1=word1.length();
        int length2=word2.length();
        int[][] DParray=new int[2][length1+1];
        for(int i=0;i<=length1;++i)
            DParray[0][i]=i;
                //recursive case
        for(int i=1;i<=length2;++i){                                            
            for(int j=0;j<=length1;++j){
            
            if(j==0)DParray[i%2][j]=i;
            
            else if(word1.charAt(j-1)==word2.charAt(i-1))DParray[i%2][j]=DParray[(i-1)%2][j-1];
                
            
 
            else DParray[i%2][j]=1+Math.min(DParray[(i-1)%2][j-1]
                                        ,Math.min(DParray[(i-1)%2][j],DParray[(i%2)][j-1]));   
            
            }
        }
        return DParray[length2%2][length1];
    }
	public static void main(String[] args) {
		// TODO 自動產生的方法 Stub

	}

}
