class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> res=new ArrayList<>();
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<arr.length-1;++i){
            int diff=arr[i+1]-arr[i];
            if(diff<mini){
                mini=diff;
                res.clear();
                res.add(Arrays.asList(arr[i],arr[i+1]));
            }
            else if(diff==mini)
                res.add(Arrays.asList(arr[i],arr[i+1]));
        }
        return res;
    }
}