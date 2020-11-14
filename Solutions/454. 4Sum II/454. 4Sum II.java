class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int res=0;
        var map=new HashMap<Integer,Integer>();
        for(var a:A)
            for(var b:B){
                if(map.containsKey(a+b))
                    map.put(a+b,map.get(a+b)+1);
                else
                    map.put(a+b,1);
                }
        for(var c:C)
            for(var d:D){
                if(map.containsKey(-c-d))
                    res+=map.get(-c-d);
            }
        return res;
    }
}