func maximum69Number (num int) int {
    maxdigit,currdigit:=0,1
    n:=num
    for n>0{
        if n%10==6{
            maxdigit=currdigit
        }
        currdigit*=10
        n/=10       
    }
    return num+3*maxdigit
}