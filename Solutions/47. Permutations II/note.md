# Same as [46. Permutations](https://github.com/ErnestL1n/LeetCode/blob/master/Solutions/46.%20Permutations/note.md)
### In addition: Add hashset as nums[i] as key to avoid duplication or doing exchanging with nums[begin] 


# Basic notes:
  1. [golang builds set with map](https://stackoverflow.com/questions/34018908/golang-why-dont-we-have-a-set-datastructure)
  
      ```golang
      //create a set from map
      s := map[int]bool{5: true, 2: true}
      _, ok := s[6] // check for existence
      s[8] = true // add element 
      delete(s, 2) // remove element
      
      //Union
      s_union := map[int]bool{}
      for k, _ := range s1{
          s_union[k] = true
      }
      for k, _ := range s2{
          s_union[k] = true
      }
      
      //Intersection
      s_intersection := map[int]bool{}
      for k,_ := range s1 { 
        if s2[k] {
          s_intersection[k] = true
        }
      }
      ```
      
 2. python can only call 
      ```python 
      s=set()
      ```
