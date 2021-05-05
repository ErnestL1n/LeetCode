class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return foo(nums1,nums2)+foo(nums2,nums1);
    }
    int foo(vector<int>& nums1,vector<int>& nums2){
        unordered_map<int,int> m;
        int res=0;
        for(auto& n2:nums2)
            ++m[n2];
        for(auto& n1:nums1){
            long target=pow(n1,2);
            for(auto& [k,cnt]:m){
                if(target%k or m.count(target/k)==0)
                    continue;
                if(target/k==k)
                    res+=cnt*(cnt-1);
                else
                    res+=cnt*m[target/k];
            }
        }
        return res/2;
    }
};