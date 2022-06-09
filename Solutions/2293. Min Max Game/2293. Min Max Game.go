func minMaxGame(nums []int) int {
    for n:=len(nums);n>1;n-=(n/2){
        for i:=0;i<n/2;i+=1{
            if i%2==1{
                nums[i]=max(nums[2*i],nums[2*i+1]);
            }else{
                nums[i]=min(nums[2*i],nums[2*i+1]);
            }
        }
    }
    return nums[0];
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}