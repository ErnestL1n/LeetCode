## [Idea](https://leetcode.com/problems/stone-game-vii/discuss/970262/C%2B%2B-Bottom-up-DP-O(N2)-time)
  * Let ```dp[i][j]``` be the maximum difference the first player can get if the players play on ```A[i..j]```.
    
    ```
    dp[i][j] = max(
                sum(i + 1, j) - dp[i + 1][j],   // if the first player choose `A[i]`
                sum(i, j - 1) - dp[i][j - 1]    // if the first player choose `A[j]`
              )
    ```
    where ```sum(i, j)``` is ```A[i] + ... + A[j]```. We can get ```sum(i, j)``` using prefix sum array.
    
    Each player needs to play optimally to get as many points as possible and make the other player get as less as possible. So the game is actually the same for both of them.

    After Alice finshes the her first round, ignoring the points Alice made there, the game to Bob is exactly the same as if he is the first player.

    So each round on ```A[i..j]```, no matter who plays first, the first player always has two options:

      1. pick ```A[i]```, the first player get ```sum(i + 1, j)``` points, and we need to deduct the maximum point difference the next player can get in the remaining game, i.e. ```dp[i + 1][j]```
      2. pick ```A[j]```, the first player get ```sum(i, j - 1)``` points, and we need to deduct the maximum point difference the next player can get in the remaining game, i.e. ```dp[i][j - 1]```
    And the first player simply pick the option more advantageous to him/her.
