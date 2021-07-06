func lengthOfLastWord(s string) int {
    s+=string(' ')
    tmp:=""
    for i:=0;i<len(s);i+=1{
        if len(tmp)>0 && string(s[i])!=string(' '){
            tmp=""
        }
        for string(s[i])!=string(' '){
            tmp+=string(s[i])
            i+=1
        }
    }
    if len(tmp)>0{
        return len(tmp)
    }
    return 0
}