func candy(r []int) int {
    res,up,down,peek:=1,0,0,0
    for i:=1;i<len(r);i+=1{
        if r[i]>r[i-1]{
            up+=1
            peek=up
            down=0
            res+=1+up
        }else if r[i]==r[i-1]{
            down,peek,up=0,0,0
            res+=1
        }else if r[i]<r[i-1]{
            down+=1
            up=0
            if peek>=down{
                res+=down
            }else{
                res+=down+1
            }
        }
    }
    return res
}