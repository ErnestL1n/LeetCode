func validPalindrome(s string) bool {
    lo,hi:=0,len(s)-1
    for lo<hi{
        if s[lo]!=s[hi]{
            if isPal(&s,lo+1,hi) || isPal(&s,lo,hi-1){
                return true
            }
            return false
        }
        lo,hi=lo+1,hi-1
    }
    return true
}

func isPal(s *string,lo,hi int) bool {
    for lo<hi{
        if((*s)[lo]!=(*s)[hi]){
            return false
        }
        lo,hi=lo+1,hi-1
    }
    return true
}
