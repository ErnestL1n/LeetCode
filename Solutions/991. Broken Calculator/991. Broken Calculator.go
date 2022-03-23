func brokenCalc(startValue int, target int) int {
    res:=0
    for startValue<target{
        if target%2==0{
            target=target/2
        }else{
            target+=1   
        }
        res+=1
    }
    return res+startValue-target
}