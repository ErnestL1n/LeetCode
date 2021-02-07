class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0,j=0;j<A.size();++j){
            if(A[j]%2==0){
                int tmp=A[i];
                A[i++]=A[j];
                A[j]=tmp;
            }
        }
        return A;
    }
};