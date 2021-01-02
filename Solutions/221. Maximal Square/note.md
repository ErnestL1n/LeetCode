## Python creates 2-D list :
  ```python
   dp=[[0]*len(m[0]) for _ in range(len(m))]
   ```
## Go converts Byte to Int :
  ```go
  dp[i][j]=int(m[i][j]-'0')  // m[i][j] stores bytes
  
  //creates 2-D array
  dp:=make([][]int,len(m))
  for i,_:=range(dp){dp[i]=make([]int,len(m[0]))}
  ```
  
