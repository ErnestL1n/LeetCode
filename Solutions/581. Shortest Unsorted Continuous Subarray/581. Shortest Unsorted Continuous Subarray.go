func findUnsortedSubarray(nums []int) int {
    //initialize end = -2 is a smart move. we can always return end - beg + 1
    //no need to check if the array is already sorted.
    n,st,ed:=len(nums),-1,-2
    mx,mn:=math.MinInt64,math.MaxInt64
    for i:=0;i<n;i+=1{
        mx=max(mx,nums[i])
        mn=min(mn,nums[n-i-1])
        if mx>nums[i]{
            ed=i
        }
        if mn<nums[n-i-1]{
            st=n-i-1
        }
    }
    return ed-st+1
}

func max(x,y int) int {
    if x>y{
        return x
    }
    return y
}

func min(x,y int) int {
    if x<y{
        return x
    }
    return y
}