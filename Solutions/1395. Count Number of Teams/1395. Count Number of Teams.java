//simple approach
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

//counting approach
class Solution {
    private int[] arr;
    public int numTeams(int[] rating) {
        arr=rating;
        return foo()+bar();
    }
    private int foo() {
        int[] dp=new int[arr.length];
        // first loop, count of smaller on the left;
        for (int i=0;i<arr.length;++i) {
            for (int j=0;j<i;++j) {
                if (arr[j]<arr[i]){
                    ++dp[i];
                }
            }
        }
        //second loop, collct count of subsequence ending of i;
        int res=0;
        for (int i=0; i<arr.length;++i) {
            for (int j=0;j<i;++j) {
                if(arr[j]<arr[i]) {
                    res+=dp[j];
                }
            }
        }
        return res;
    }
    private int bar() {  // same as count Larger
        int[] dp = new int[arr.length];
        for (int i=0;i<arr.length;++i) {
            for (int j=0;j<i;++j) {
                if (arr[j]>arr[i]) {
                    ++dp[i];
                }
            }
        }
        int res = 0;
        for (int i=0;i<arr.length;++i) {
            for (int j=0;j<i;++j) {
                if(arr[j]>arr[i]) {
                    res+=dp[j];
                }
            }
        }
        return res;
    }
}