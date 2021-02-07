class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0,j=0;j<A.size();++j){
            if(A[j]%2==0)
                swap(A[j],A[i++]);
        }
        return A;
    }
};