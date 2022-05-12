func mostFrequent(nums []int, key int) int {
    cnt,res:=make([]int,1001),0
    for i:=1;i<len(nums);i+=1{
        if nums[i-1]==key{
            cnt[nums[i]]+=1
            if cnt[nums[i]]>cnt[res]{
                res=nums[i]
            }
        }
    }
    return res
}