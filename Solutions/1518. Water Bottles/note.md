## [Observation](https://leetcode.com/problems/water-bottles/discuss/743148/JavaPython-3-O(logN)-and-O(1)-codes-w-brief-explanation-and-analysis.)
  * ```O(1)```:
    * ```1 full``` bottle of water = ```1``` empty bottle + ```1``` bottle of water
```e.g.,``` for test case ```9, 3```:
```3``` empty bottles can exchange ```1 full``` bottle of water implies ```3``` empty bottles exchange ```1``` empty bottle + ```1``` bottle of water, which in turn means ```(3 - 1) =2``` empty bottles can exchange ```1``` bottle of water.
<strong>Further more, if you only have ```2``` empty bottles remaining```(The edge case)```, you can NOT exchange it for ```1``` bottle of water</strong>
Substitue the number ```3``` above by numExchange, we get a important conclusion:
(numExchange - 1) empty bottles can exchange ```1``` bottle of water, unless you have only numExchange left.
<strong>When we meet ```edge case```we need to minus 1 additionally in the numerator (numBottles - 1)/ (numExchange - 1) to avoid having only numExchange left but unable to exchange ```1``` bottle of water</strong>
Note: Under  ```(numExchange - 1)  * n ``` condition , we call it edge case

