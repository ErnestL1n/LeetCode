class Solution:
    def flipAndInvertImage(self, a: List[List[int]]) -> List[List[int]]:
        def reverse(row):
            l,r=0,len(row)-1
            while l<r:
                row[l],row[r]=row[r],row[l]
                l+=1
                r-=1
        def invert(row):
            for i in range(len(row)):
                if row[i]:
                    row[i]=0
                else:
                    row[i]=1
        for row in a:
            reverse(row)
            invert(row)
        return a