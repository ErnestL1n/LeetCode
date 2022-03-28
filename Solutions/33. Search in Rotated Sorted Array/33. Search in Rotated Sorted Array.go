func search(nums []int, target int) int {
    lo,hi:=0,len(nums)-1
    // find smallest element
    for lo<hi{
        mid:=(lo+hi)/2
        if nums[mid]>nums[hi]{
            lo=mid+1
        }else{
            hi=mid
        }
    }
    rotate:=lo
    lo,hi=0,len(nums)-1
    for lo<=hi{
        mid:=(lo+hi)/2
        realmid:=(mid+rotate)%len(nums)
        if nums[realmid]==target{
            return realmid
        }
        if nums[realmid]<target{
            lo=mid+1
        }else{
            hi=mid-1
        }
    }
    return -1
}