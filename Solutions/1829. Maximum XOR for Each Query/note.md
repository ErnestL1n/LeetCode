## [How is maximum always ```2^maximumBit - 1``` ?](https://leetcode.com/problems/maximum-xor-for-each-query/discuss/1163057/Easy-O(N)-Solution-w-Explanation-or-Max-XOR-2maximumBit-1)
* It is given that all elements of the nums are in the range [```0, ^maximumBit - 1```]. And, after xor-ing the whole nums array, we will always have a final value (lets call it XOR) in between [```0, 2^maximumBit - 1```].

* Now, we can xor this value with any number from the range [```0, 2^maximumBit - 1```]. To maximize it, we can always choose a value from that range which when xor-ed with XOR(above obtained value), will maximize it to ```2^maximumBit - 1```.
```
Some Examples:
Here, XOR will denote the xor of all elements of original nums array.

Let maximumBit = 3.
Our range will be from [0, 7]. Now, if - 

1. XOR = 1 (001) :  we can choose to xor it with 6 so that maximum xor for query will become '2^maximumBit - 1 = 7'
	   ^ 6 (110)
	   ----------
		    111
			
2. XOR = 2 (010) :  we can choose to xor it with 5 so that maximum xor for query will become '2^maximumBit - 1 = 7'
	   ^ 5 (101)
	   ----------
		    111

3. XOR = 3 (011) :  we can choose to xor it with 4 
	   ^ 4 (100)
	   ----------
		    111
			
4. XOR = 4 (100) :  we can choose to xor it with 3
	   ^ 3 (011)
	   ----------
		    111	
			
And so on for any other cases, we can choose a value to maximize xor to '2^maximumBit-1'
```
Also, after we first calculate the XOR for original nums array, the only thing that changes in subsequent queries is that the last element of nums is removed.

So, we can just use the previous XOR and xor it with element which is to be removed. The element to be removed will be xor-ed twice and cancel out each other and we will get the final answer of that query.
