## Note
  * [Multiple assignment and evaluation order in Python](https://stackoverflow.com/questions/8725673/multiple-assignment-and-evaluation-order-in-python)
    * ex: ```rev, rev.next, slow = slow, rev, slow.next```  in python
    * equals to ```ListNode* tmp = rev; rev = slow; slow = slow -> next; rev -> next = tmp; ``` in c++
  * [Reference to a pointer in C++ with examples and applications](https://www.geeksforgeeks.org/reference-to-a-pointer-in-c-with-examples-and-applications/)
## This problem
  *  while comparing the two halves, restore the list to its original state by reversing the first half back. Not that the OJ or anyone else cares.
