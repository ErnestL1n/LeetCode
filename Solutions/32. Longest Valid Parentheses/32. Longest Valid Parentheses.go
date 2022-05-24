func longestValidParentheses(s string) int {
    n,res:=len(s),0
    var stk []int
    for i:=0;i<n;i+=1{
        if s[i]=='('{
            stk=append(stk,i)
        }else{
            if len(stk)>0{
                if s[stk[len(stk)-1]]=='('{
                    stk=stk[:len(stk)-1]
                }else{
                    stk=append(stk,i)
                }
            }else{
                stk=append(stk,i)
            }
        }
    }
    if len(stk)==0{
        res=n
    }else{
        x,y:=n,0
        for len(stk)>0{
            y=stk[len(stk)-1];stk=stk[:len(stk)-1]
            res=max(res,x-y-1)
            x=y
        }
        res=max(res,x)
    }
    return res
}

func max (i,j int) int{
    if i>j{
        return i
    }
    return j
}