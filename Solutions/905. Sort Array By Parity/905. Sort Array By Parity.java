class Solution {
    public int[] sortArrayByParity(int[] A) {
        for(int i=0,j=0;j<A.length;++j){
            if(A[j]%2==0){
                swap(A,i,j);
                ++i;
            }
        }
        return A;
    }
    private void swap(int[] a,int i,int j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
}