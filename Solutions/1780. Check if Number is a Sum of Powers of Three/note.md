## [Idea](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/discuss/1096272/JavaPython-3-Iterative-code-w-brief-explanation-and-analysis.)
  * think of n in ternary form
  * each digit is ```3^i```, and ternary number is sum of them
  * to have distinct powers of ```3``` to sum up ```n```:
  * digit can be ```0``` i.e. no such number
  * digit can be ```1``` i.e. one such number
  * a digit cannot be ```2``` because then there is two of ```3^i```, therefore not distinct
### Take an example:
  * ```19``` (decimal form) == ```201``` (ternary form)
    * we get ```20=2*pow(3,2)+0*pow(3,1)+1*pow(3,0)``` , which has two ```pow(3,2)``` that is not distinct
