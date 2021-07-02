//binary search 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo=0,hi=arr.size()-k;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(x<=arr[mid])
                hi=mid;
            else if(x>=arr[mid+k])
                lo=mid+1;
            else if(x-arr[mid]>arr[mid+k]-x)
                lo=mid+1;
            else
                hi=mid;
        }
        //break condition lo must move
        //then , lo==hi
        //return vector<int>(arr.size()+hi,arr.size()+hi+k)
        //also be accepted
        return vector<int>(arr.size()+lo,arr.size()+lo+k);
    }
};

//simplify binary search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo=0,hi=arr.size()-k;
        while(lo<hi){
            int mid=(lo+hi)/2;
            //x is closer to starting point mid+k
            if(x-arr[mid]>arr[mid+k]-x)
                lo=mid+1;
            else
                hi=mid;
        }
        return vector<int>(arr.begin()+lo,arr.begin()+lo+k);
    }
};

//Two pointers solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo=0,hi=arr.size()-1;
        while(lo+k<=hi){
            if(abs(arr[lo]-x)>abs(arr[hi]-x))
                ++lo;
            else
                --hi;
        }
        //break,lo~hi must contain exactly k elements
        return vector<int>(arr.begin()+lo,arr.begin()+hi+1);
    }
};