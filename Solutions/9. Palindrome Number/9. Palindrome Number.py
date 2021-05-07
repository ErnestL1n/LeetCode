class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0 or (x!=0 and x%10==0):
            return False
        half=0
        while x>half:
            half=half*10+x%10
            x//=10
        return half==x or half//10==x