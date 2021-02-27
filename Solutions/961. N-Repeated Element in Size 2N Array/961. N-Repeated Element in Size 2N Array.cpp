class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int cnt[10000]={};
        for(int a:A)
            if(cnt[a]++==1)
                return a;
        return -1;
    }
};

class Solution {
public:
        int repeatedNTimes(vector<int>& A, int i = 0, int j = 0) {
            while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j);
            return A[i];
    }
};