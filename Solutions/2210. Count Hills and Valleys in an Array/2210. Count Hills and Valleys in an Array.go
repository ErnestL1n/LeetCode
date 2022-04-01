func countHillValley(nums []int) int {
    var tmp []int
    for i,_:=range nums{
        if i==0 || nums[i]!=nums[i-1]{
            tmp=append(tmp,nums[i])
        }
    }
    res:=0
    for i:=1;i<len(tmp)-1;i+=1{
        if (tmp[i-1]<tmp[i] && tmp[i]>tmp[i+1]) || (tmp[i-1]>tmp[i] && tmp[i]<tmp[i+1]){
            res+=1
        }
    }
    return res
}