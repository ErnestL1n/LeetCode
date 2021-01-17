class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        res = 0
        for row in range(len(matrix)):
            for col in range(len(matrix[0])):
                if matrix[row][col] != 0 and row > 0:
                    matrix[row][col] += matrix[row - 1][col]

            curr=sorted(matrix[row], reverse=True)
            for j in range(len(matrix[0])):
                res = max(res, curr[j] * (j + 1))
            print(curr)
        return res