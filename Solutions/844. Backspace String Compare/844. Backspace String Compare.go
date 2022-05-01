func backspaceCompare(s string, t string) bool {
    i,j,back:=len(s)-1,len(t)-1,0
    for true{
        back=0
        for i>=0 && (back>0 || s[i]=='#'){
            if s[i]=='#'{
                back+=1
            }else{
                back-=1
            }
            i-=1
        }
        back=0
        for j>=0 && (back>0 || t[j]=='#'){
            if t[j]=='#'{
                back+=1
            }else{
                back-=1
            }
            j-=1
        }
        if i>=0 && j>=0 && s[i]==t[j]{
            i-=1;j-=1
        }else{
            break
        }
    }
    return i==-1 && j==-1
}