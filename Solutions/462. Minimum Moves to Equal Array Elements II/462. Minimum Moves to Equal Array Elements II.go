func minMoves2(nums []int) int {
    sort.Ints(nums)
    i,j:=0,len(nums)-1
    cnt:=0
    for i<j{
        cnt+=nums[j]-nums[i]
        i,j=i+1,j-1
    }
    return cnt
}