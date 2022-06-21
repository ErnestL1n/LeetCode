func countOperations(num1 int, num2 int) int {
    cnt:=0
    for min(num1,num2)>0{
        if num1<num2{
            tmp:=num1
            num1=num2
            num2=tmp
        }
        cnt+=num1/num2
        num1%=num2
    }
    return cnt
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}