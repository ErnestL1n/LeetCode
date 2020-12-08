# [Dp idea](https://leetcode.com/problems/01-matrix/discuss/101051/Simple-Java-solution-beat-99-(use-DP)) & [BFS idea](https://leetcode.com/problems/01-matrix/discuss/101021/Java-Solution-BFS)

## keep in mind 
1. In DP solution:
	the second iteration for the nested for loop,we have to compare the above nested for loop result,that is,```min(upcell,leftcell)``` which is written into ```matrix[i][j]```,thus we need
	```min(matrix[i][j],min(downcell,rightcell))``` to compute the final result
	
2. In BFS solution
	we use the current location,which is ```matrix[i][j]```, to visit neighbor ```matrix[r][c]``` in order to find out whether it is fit to update the value
