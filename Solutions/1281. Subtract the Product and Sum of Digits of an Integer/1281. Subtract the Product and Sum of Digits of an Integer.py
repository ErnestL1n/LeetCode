class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        s,pro=0,1
        while n>0:
            tmp=n%10
            s+=tmp
            pro*=tmp
            n//=10
        return pro-s