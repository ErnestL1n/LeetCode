## [C++ 2-liner (count_if)](https://leetcode.com/problems/count-items-matching-a-rule/discuss/1086218/C%2B%2B-2-liner-(count_if))
### [C++ Lambda Expression ](https://blog.gtwang.org/programming/lambda-expression-in-c11/)
### [count_if() in C++ STL](https://www.geeksforgeeks.org/count_if-in-c/)
### [const auto&](https://stackoverflow.com/questions/26541920/is-it-a-good-practice-to-use-const-auto-in-a-range-for-to-process-the-element/26543405)

#### [[=]：lambda-introducer，or capture clause。](https://blog.gtwang.org/programming/lambda-expression-in-c11/)
```
In this case,results are the same
return count_if(begin(items),end(items),[=](const auto& i){return i[type]==ruleValue;});
return count_if(begin(items),end(items),[&](const auto& i){return i[type]==ruleValue;});
```
