class Solution {
    public int findMaxLength(int[] nums) {
        var m=new HashMap<Integer,Integer>();
        int res=0,cnt=0,n=nums.length;
        m.put(0,0);
        for(int i=0;i<n;++i){
            if(nums[i]==1){
                ++cnt;
            }else{
                --cnt;
            }
            if(m.containsKey(cnt)){
                res=Math.max(res,i+1-m.get(cnt));
            }else{
                m.put(cnt,i+1);
            }
        }
        return res;
    }
}