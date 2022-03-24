func canPartitionKSubsets(nums []int, k int) bool {
    s:=0
    for _,n:=range(nums){
        s+=n
    }
    if s%k!=0{
        return false
    }
    sort.Sort(sort.Reverse(sort.IntSlice(nums)))
    sums:=make([]int,len(nums))
    return foo(sums,nums,k,s/k,0)
}

func foo(sums,nums []int,k,subset_sum,begin int) bool{
    if begin==len(nums){
        for i:=0;i<k;i+=1{
            if sums[i]!=subset_sum{
                return false
            }
        }
        return true
    }
    for i:=0;i<k;i+=1{
        if sums[i]+nums[begin]<=subset_sum{
            sums[i]+=nums[begin]
            if foo(sums,nums,k,subset_sum,begin+1){
                return true
            }
            sums[i]-=nums[begin]
        }
    }
    return false
}