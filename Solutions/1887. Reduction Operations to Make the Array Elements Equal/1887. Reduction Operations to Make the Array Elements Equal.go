func reductionOperations(nums []int) int {
    res,sz:=0,len(nums)
    sort.Ints(nums)
    for i:=sz-1;i>0;i-=1{
        if nums[i]!=nums[i-1]{
            res+=sz-i
        }
    }
    return res
}