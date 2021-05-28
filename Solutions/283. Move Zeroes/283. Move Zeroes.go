func moveZeroes(nums []int)  {
    j:=0
    for _,n:=range(nums){
        if n!=0{
            nums[j]=n
            j+=1
        }
    }
    for j<len(nums){
        nums[j]=0
        j+=1
    }
}