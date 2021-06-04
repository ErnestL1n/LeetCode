class Solution:
    def maximum69Number (self, num: int) -> int:
        maxdigit,currdigit=0,1
        n=num
        while n>0:
            if n%10==6:
                maxdigit=currdigit
            currdigit*=10
            n//=10
        return num+maxdigit*3