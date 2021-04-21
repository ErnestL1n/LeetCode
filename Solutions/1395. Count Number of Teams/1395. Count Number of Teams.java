class Solution {
    public int numTeams(int[] rating) {
        int res=0;
        for(int i=0;i<rating.length;i++){
            int leftsmall=0,rightsmall=0,leftlarge=0,rightlarge=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])leftsmall++;
                else leftlarge++;
            }
            for(int k=i+1;k<rating.length;k++){
                if(rating[k]<rating[i])rightsmall++;
                else rightlarge++;
            }
            res+=leftsmall*rightlarge+leftlarge*rightsmall;
        }
        return res;
    }
}