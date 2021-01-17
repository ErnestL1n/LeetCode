// must TLE O(n!)
class Solution {
public:
    set<array<int,4>> s;
    int tupleSameProduct(vector<int>& nums) {
        int res=0;
        foo(nums,res,0);
        return res;
    }
    void foo(vector<int>& nums,int& res,int begin){
        if(begin==nums.size()){
            if(nums[begin-1]*nums[begin-2]==nums[begin-3]*nums[begin-4]&&s.find({nums[begin-1],nums[begin-2],nums[begin-3],nums[begin-4]})==s.end()){
                s.insert({nums[begin-1],nums[begin-2],nums[begin-3],nums[begin-4]});
                ++res;
            }
            return;
        }
        for(int i=begin;i<nums.size();++i){ 
            swap(nums[begin],nums[i]);
            foo(nums,res,begin+1);
            swap(nums[begin],nums[i]);   
        }
        return;
    }
};


//correct solution
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for(int i=0;i<nums.size();++i)
            for(int j=i+1;j<nums.size();++j){
                int prod=nums[i]*nums[j];
                res+=8*m[prod];
                ++m[prod];
            }
        return res;
    }
};