## Note
  * [Multiple assignment and evaluation order in Python](https://stackoverflow.com/questions/8725673/multiple-assignment-and-evaluation-order-in-python)
    * ex: ```rev, rev.next, slow = slow, rev, slow.next``` 
    * equals to ```ListNode* tmp = rev; rev = slow; slow = slow -> next; rev -> next = tmp; ``` in c++

## This problem
  *  while comparing the two halves, restore the list to its original state by reversing the first half back. Not that the OJ or anyone else cares.
