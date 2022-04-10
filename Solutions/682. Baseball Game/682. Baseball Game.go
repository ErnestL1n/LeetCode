func calPoints(ops []string) int {
    var stk []int
    for _,o:=range ops{
        if o=="C"{
            stk=stk[:len(stk)-1]
        }else if o=="D"{
            stk=append(stk,stk[len(stk)-1]*2)
        }else if o=="+"{
            x:=stk[len(stk)-1];stk=stk[:len(stk)-1]
            y:=stk[len(stk)-1]
            stk=append(stk,x)
            stk=append(stk,x+y)
        }else{
            i,err:=strconv.Atoi(o)
            if err==nil{
                stk=append(stk,i)
            }
        }
    }
    res:=0
    for _,s:=range stk{
        res+=s
    }
    return res
}