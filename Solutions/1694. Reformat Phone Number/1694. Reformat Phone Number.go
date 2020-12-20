func reformatNumber(number string) string {
    var tmp string
    for _,c:=range(number){
        if c!=' '&&c!='-'{
            tmp+=string(c)
        }
    }
    var res string
    for i:=0;i<len(tmp);{
        if(len(tmp)-i==4){
            res+=string(tmp[i])
            res+=string(tmp[i+1])
            i+=2
        }else if(len(tmp)-i==2){
            res+=string(tmp[i])
            res+=string(tmp[i+1])
            break
        }else if(len(tmp)-i==3){
            res+=string(tmp[i])
            res+=string(tmp[i+1])
            res+=string(tmp[i+2])
            break
        }else{
            res+=string(tmp[i])
            res+=string(tmp[i+1])
            res+=string(tmp[i+2])
            i+=3
        }
        res+=string('-')
    }
    return res
}