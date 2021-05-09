func maxDistance(nums1 []int, nums2 []int) int {
    res:=0
    for i:=0;i<len(nums1);i+=1{
        tmp:=bs(nums1[i],nums2)
        if tmp<i{
            continue
        }
        if res<tmp-i{
            res=tmp-i
        }
    }
    return res
}
func bs(x int,nums []int) int{
    l,r:=0,len(nums)-1
    for l<=r{
        mid:=(l+r)/2
        if x>nums[mid]{
            r=mid-1
        }else{
            l=mid+1
        }
    }
    return r
}


//Two Pointers
func maxDistance(nums1 []int, nums2 []int) int {
    i,j,n1,n2,res:=0,0,len(nums1),len(nums2),0
    for i<n1 && j<n2{
        if nums1[i]>nums2[j]{
            i+=1
        }else{
            res=max(res,j-i)
            j+=1
        }
    }
    return res
}
func max(i,j int)int{
    if(i>j){
        return i
    }
    return j
}