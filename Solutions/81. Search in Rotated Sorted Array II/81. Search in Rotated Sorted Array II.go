func search(nums []int, target int) bool {
    lo,hi:=0,len(nums)-1
    for lo<=hi{
        mid:=(lo+hi)/2
        if nums[mid]==target{
            return true
        }
        if nums[lo]==nums[mid] && nums[mid]==nums[hi]{
            lo+=1
            hi-=1
        }else if nums[lo]<=nums[mid]{
            if nums[lo]<=target && nums[mid]>target{
                hi=mid-1
            }else{
                lo=mid+1
            }
        }else{
            if nums[mid]<target && nums[hi]>=target{
                lo=mid+1
            }else{
                hi=mid-1
            }
        }
    }
    return false
}