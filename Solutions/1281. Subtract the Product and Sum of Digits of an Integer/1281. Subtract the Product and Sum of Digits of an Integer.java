class Solution {
    public int subtractProductAndSum(int n) {
        int s=0,pro=1;
        while(n>0){
            int tmp=n%10;
            s+=tmp;pro*=tmp;
            n/=10;
        }
        return pro-s;
    }
}