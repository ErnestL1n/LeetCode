class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return count(nums1,nums2)+count(nums2,nums1);
    }
    int count(vector<int>& nums1,vector<int>& nums2){
        int res=0;
        unordered_map<int,int> m;
        for(int n:nums2)++m[n];
        for(int a:nums1){
            long target=(long)a*a;
            for(auto& [k,v]:m){
                if(target%k!=0||!m.count(target/k))continue;
                if(target/k==k)res+=v*(v-1);
                else
                    res+=v*m[target/k];
            }
        }
        return res/2;
    }
};