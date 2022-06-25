func checkPossibility(nums []int) bool {
    cnt:=0
    for i:=1;i<len(nums) && cnt<=1;i+=1{
        if nums[i-1]>nums[i]{
            cnt+=1
            if i<2 || nums[i-2]<=nums[i]{
                nums[i-1]=nums[i]
            }else{
                nums[i]=nums[i-1]
            }
        }
    }
    return cnt<=1
}