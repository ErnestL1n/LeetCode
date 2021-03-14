## [Idea](https://leetcode.com/problems/maximum-average-pass-ratio/discuss/1108305/C%2B%2B-Greedy-Max-Heap-O(m-log-n)) 

How much of profit in score can we get if we add one extra student to a particular class? Send an extra student to the class with the most profit; repeat till you run out of students.

Let's track profits for all classes in a max heap. While we still have extra students, we pick a class that gives us the maximum profit, add a student, calculate new profit and put it back to the heap.

To avoid iterating through the max heap in the end, we can track the total score as we go.

### Complexity Analysis
  * Time: O(m log n), where n and m are the number of classes and extra students.
    * Caveat:The complexity for the code above is O((n + m) log n). To achieve O(m log n), we need construct the heap in O(n), e.g. by using ```make_heap```.
For the purpose of complexity analsyis, I assume that we build the initial heap in O(n)
  * Memory: O(n) to hold the information about classes.

### [Difference between Priority-Queue and Heap](https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C%2B%2B-implementation)
  1.Heap is a kind of data structure. It is a name for a particular way of storing data that makes certain operations very efficient. We can use a tree or array to describe it.
```
       18
      /	\
     10	 16
    / \   / \
   9  5  8  12
18, 10, 16, 9, 5, 8, 12
``` 
  2.Priority queue is an abstract datatype. It is a shorthand way of describing a particular interface and behavior, and says nothing about the underlying implementation.

A heap is a very good data structure to implement a priority queue. The operations which are made efficient by the heap data structure are the operations that the priority queue interface needs.

    
#### [When should I use make_heap vs. Priority Queue?](https://stackoverflow.com/questions/11266360/when-should-i-use-make-heap-vs-priority-queue#:~:text=A%20priority_queue%20is%20(at%20least%20normally)%20implemented%20as%20a%20heap.&text=When%20you%20use%20make_heap%20you,the%20head%20of%20the%20queue)
#### [std::make_heap](http://www.cplusplus.com/reference/algorithm/make_heap/)
