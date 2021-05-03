class Solution {
    public static boolean canMakeArithmeticProgression(int[] arr) {
        Set<Integer> seen=new HashSet<>();
        int n=arr.length,min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        for(int a:arr){
            min=Math.min(a,min);
            max=Math.max(a,max);
            seen.add(a);
        }
        int diff=max-min;
        if(diff%(n-1)!=0)return false;
        diff/=(n-1);
        while(--n > 0){
            if(!seen.contains(min))
                return false;
            min+=diff;
        }
        return true;
    }
}

class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        for(int i=1;i<arr.length-1;++i){
            if(arr[i-1]-arr[i]!=arr[i]-arr[i+1])
                return false;
        }
        return true;
    }
}