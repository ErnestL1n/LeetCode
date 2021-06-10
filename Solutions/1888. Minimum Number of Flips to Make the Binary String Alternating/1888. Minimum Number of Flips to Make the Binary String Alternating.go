func minFlips(s string) int {
    n,cnt1,cnt2:=len(s),0,0
    res:=n
    for i:=0;i<2*n;i+=1{
        c:=string(s[i%n])
        var cc string
        if i%2==0{
            cc=string('0')
        }else{
            cc=string('1')
        }
        if c!=cc{
            cnt1+=1
        }else{
            cnt2+=1
        }
        if i>=n{
            idx:=i-n
            if idx%2==0{
                cc=string('0')
            }else{
                cc=string('1')
            }
            if string(s[idx])!=cc{
                cnt1-=1
            }else{
                cnt2-=1
            }
        }
        if i>=n-1{
            res=min(res,min(cnt1,cnt2))
        }
    }
    return res
}
func min(a,b int)int{
    if a<b{
        return a
    }
    return b
}



//speed up a little bit
func minFlips(s string) int {
    n,cnt1,cnt2:=len(s),0,0
    res:=n
    for i:=0;i<2*n;i+=1{
        c:=s[i%n]=='1'
        var cc bool
        if i%2==0{
            cc=false
        }else{
            cc=true
        }
        if c!=cc{
            cnt1+=1
        }else{
            cnt2+=1
        }
        if i>=n{
            idx:=i-n
            if idx%2==0{
                cc=false
            }else{
                cc=true
            }
            c=s[idx]=='1'
            if c!=cc{
                cnt1-=1
            }else{
                cnt2-=1
            }
        }
        if i>=n-1{
            res=min(res,min(cnt1,cnt2))
        }
    }
    return res
}
func min(a,b int)int{
    if a<b{
        return a
    }
    return b
}