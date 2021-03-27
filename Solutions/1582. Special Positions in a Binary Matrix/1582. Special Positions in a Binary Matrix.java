// HashMap solution
class Solution {
    public int numSpecial(int[][] mat) {
        int res=0;
        HashMap<Integer,Integer> row=new HashMap<>(),column=new HashMap<>();
        for(int i=0;i<mat.length;++i)
            for(int j=0;j<mat[0].length;++j){
                if(mat[i][j]==1){
                    row.put(i,row.getOrDefault(i,0)+1);
                    column.put(j,column.getOrDefault(j,0)+1);
                }
            }           
        for(int i=0;i<mat.length;++i)
            for(int j=0;j<mat[0].length;++j){
                if(mat[i][j]==1&&row.get(i)==1&&column.get(j)==1)
                    ++res;
            }
        return res;
    }
}

class Solution {
    public int numSpecial(int[][] mat) {
        int res=0;
        int[] row=new int[mat.length],column=new int[mat[0].length];
        for(int i=0;i<mat.length;++i)
            for(int j=0;j<mat[0].length;++j){
                if(mat[i][j]==1){
                    ++row[i];++column[j];
                }
            }           
        for(int i=0;i<mat.length;++i)
            for(int j=0;j<mat[0].length;++j){
                if(mat[i][j]==1&&row[i]==1&&column[j]==1)
                    ++res;
            }
        return res;
    }
}