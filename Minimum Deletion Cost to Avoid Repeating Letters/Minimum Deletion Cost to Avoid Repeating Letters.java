class Solution {
    public int minCost(String s, int[] cost) {
        int maxcost=0,res=0;
        for(int i=0;i<s.length();++i){
            if(i>0&&s.charAt(i)!=s.charAt(i-1))
                maxcost=0;
            res+=Math.min(maxcost,cost[i]);
            maxcost=Math.max(maxcost,cost[i]);
        }
        return res;
    }
}