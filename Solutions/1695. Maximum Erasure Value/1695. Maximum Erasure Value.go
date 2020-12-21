func maximumUniqueSubarray(nums []int) int {
    i,j,tmp,res:=0,0,0,0
    set:=make(map[int]bool)
    for i<len(nums) && j<len(nums){
        if _,ok:=set[nums[i]];!ok{
            tmp+=nums[i]
            set[nums[i]]=true
            i+=1
            res=max(res,tmp)
        }else{
            delete(set,nums[j])
            tmp-=nums[j]
            j+=1
        }
    }
    return res
}

func max(a,b int) int{
    if a<b{
        return b
    }
    return a
}