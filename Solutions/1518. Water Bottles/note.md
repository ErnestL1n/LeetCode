## [Observation](https://leetcode.com/problems/water-bottles/discuss/743148/JavaPython-3-O(logN)-and-O(1)-codes-w-brief-explanation-and-analysis.)
```O(1):
Key observation: A full bottle of water = A empty bottle + One (bottle) unit of water.

e.g., for test case: 9, 3:
3 empty bottles can exchange a full bottle of water implies 3 empty bottles exchange a empty bottle + one (bottle) unit of water, which in turn means (3 - 1) = 2 empty bottles can exchange one (bottle) unit of water.

Further more, if you only have 2 empty bottles remaining, you can NOT exchange it for a (bottle) unit of water.

Substitue the number 3 above by numExchange, we get a important conclusion:
(numExchange - 1) empty bottles can exchange one (bottle) unit of water, unless you have only numExchange left.

we need to get the floor value of numBottles / (numExchange - 1), that is why we need to minus 1 additionally in the numerator: (numBottles - 1)/ (numExchange - 1).

See the explanation of a more general question here for the derivation details.
```


```
Think about it this way:
The "price" of buying a refill is handing over two empties. However, you must have your own empty bottle to receive the refill.
Therefore after drinking the initial numBottles, we "keep aside" one empty for receiving the refills (therefore we do 9 minus 1) and trade in the remaining 8 empties to get refills @ 2 bottles/refill
```
