class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(letters[n-1]<=target)
            return letters[0];
        int t=target-'a',lo=0,hi=n-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(letters[mid]-'a'<=t){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return letters[lo];
    }
};