class Solution {
    public boolean mergeTriplets(int[][] tri, int[] target) {
        int a,b,c;
        a=b=c=0;
        for(var t:tri){
            if(t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]){
                a=Math.max(a,t[0]);b=Math.max(b,t[1]);c=Math.max(c,t[2]);
            }
            if(a==target[0] && b==target[1] && c==target[2])
                return true;
        }
        return false;
    }
}