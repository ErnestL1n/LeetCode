//brute force
func subsetXORSum(nums []int) int {
    var Allsubset [][]int
    var tmp []int
    res:=0
    subset(nums,&Allsubset,tmp,0)
    for _,s:=range(Allsubset){
        k:=0
        for _,n:=range(s){
            k^=n
        }
        res+=k
    }
    return res
}
func subset(nums []int,res *[][]int,tmp []int,begin int) {
    t:=make([]int,len(tmp))
    copy(t,tmp)
    (*res)=append(*res,t)
    for i:=begin;i<len(nums);i+=1{
        tmp=append(tmp,nums[i])
        subset(nums,res,tmp,i+1)
        tmp=tmp[:len(tmp)-1]
    }
    return
}

//trick
func subsetXORSum(nums []int) int {
    res,n:=0,len(nums)
    for i:=0;i<n;i+=1{
        res|=nums[i]
    }
    res*=powInt(2,n-1)
    return res
}
func powInt(x, y int) int {
    return int(math.Pow(float64(x), float64(y)))
}