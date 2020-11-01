// We have counts of a + e + i + o + u = n
//Therefore, we can use combination with repetition formula to solve it as:
//answer = H(5, n) = C(5 + n - 1, n) = C(4 + n, n) = C(n + 4, 4) = (n+4) * (n+3) * (n+2) * (n+1) / 4!

class Solution {
public:
    int countVowelStrings(int n) {
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
    }
};

//accumulate
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp={0,1,1,1,1,1};
        for(int i=1;i<=n;++i)
            for(int k=1;k<=5;++k)
                dp[k]+=dp[k-1];
        return dp[5];
    }
};