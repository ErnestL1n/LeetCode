class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        return binarysearch(nums,0,nums.size()-1,target);
    }
    int binarysearch(vector<int>& nums,int left,int right,int target){
        if(left==right)
            return nums[left]==target?left:-1;
        else{
            int mid=(left+right)/2;
            if(target<=nums[mid])return binarysearch(nums,left,mid,target);
            else return binarysearch(nums,mid+1,right,target);
        }
    }
};

/*non-recursive version
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return -1;
    }
};


//hashmap version(not good in this case)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i)
            m[nums[i]]=i;
        if(m.find(target)!=m.end())
            return m[target];
        else
            return -1;
    }
};












*/