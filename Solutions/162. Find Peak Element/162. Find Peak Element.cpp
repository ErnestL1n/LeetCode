//Binary Search iterative O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int mid1=(lo+hi)/2;
            int mid2=mid1+1;
            if(nums[mid1]<nums[mid2])
                lo=mid2;
            else
                hi=mid1;
        }
        cout << "index is " << lo <<" number is " << nums[lo] <<"\n";
        return lo;
    }
};

//Binary Search recursive O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return foo(nums,0,nums.size()-1);
    }
    int foo(const vector<int>& nums,int lo,int hi){
        if(lo==hi)
            return lo;
        else{
            int mid1=(lo+hi)/2;
            int mid2=mid1+1;
            if(nums[mid1]<nums[mid2])
                return foo(nums,mid2,hi);
            else
                return foo(nums,lo,mid1);
        }
    }
};


//Sequential Search worst case is O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;++i)
            if(nums[i]>nums[i+1])
                return i;
        return nums.size()-1;
    }
};