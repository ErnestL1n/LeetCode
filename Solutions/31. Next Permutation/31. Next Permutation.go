func nextPermutation(nums []int)  {
    var i,j int
    n:=len(nums)
    for i=n-2;i>=0;i-=1{
        if nums[i]<nums[i+1]{
            break;
        }
    }
    if i<0{
        reverse(&nums,0,n-1)
        return
    }
    //  2,3,6,5,4,1
    //  2,4,6,5,3,1
    //  2,4,1,3,5,6
    for j=n-1;j>i;j-=1{
        if nums[j]>nums[i]{
            break
        }
    }
    nums[i],nums[j]=nums[j],nums[i]
    reverse(&nums,i+1,n-1)
}

func reverse(nums *[]int,st,ed int) {
    i,j:=st,ed
    for i<j{
        (*nums)[i],(*nums)[j]=(*nums)[j],(*nums)[i]
        i,j=i+1,j-1
    }
}