func plusOne(digits []int) []int {
    res:=make([]int,len(digits)+1)
    for i:=len(digits)-1;i>=0;i-=1{
        if(digits[i]<9){
            digits[i]+=1
            return digits
        }
        digits[i]=0
    }
    res[0]=1
    return res
}