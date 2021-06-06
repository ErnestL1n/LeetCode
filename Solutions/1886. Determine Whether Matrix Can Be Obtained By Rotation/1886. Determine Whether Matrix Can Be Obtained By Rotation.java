class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        boolean[] c=new boolean[4];
        Arrays.fill(c,true);
        int n=mat.length;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j){
                if(mat[i][j]!=target[i][j])
                    c[0]=false;
                if(mat[i][j]!=target[n-1-j][i])
                    c[1]=false;
                if(mat[i][j]!=target[j][n-1-i])
                    c[2]=false;
                if(mat[i][j]!=target[n-1-i][n-1-j])
                    c[3]=false;
            }
        return c[0] || c[1] || c[2] || c[3];
    }
}