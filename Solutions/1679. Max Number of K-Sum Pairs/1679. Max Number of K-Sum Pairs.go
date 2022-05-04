// O(NlogN)
func maxOperations(nums []int, k int) int {
    sort.Ints(nums)
    res:=0
    i,j:=0,len(nums)-1
    for i<j{
        if nums[i]+nums[j]==k{
            res,i,j=res+1,i+1,j-1
        }else if nums[i]+nums[j]>k{
            j-=1
        }else{
            i+=1
        }
    }
    return res
}