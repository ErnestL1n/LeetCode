## In the solution implemented by queue:
  ```cpp
  while (q.size()){
            for(i=q.size()-1,res=0;i>=0;--i){            //here
                auto node=q.front();q.pop();
                res+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
  ```
  The ```for loop (here comment)``` is from ```q.size()-1``` down to ```0``` , since the ```q.size()``` is resized in the ```for loop```


## Python3 recursion notification on void function referening global variables:
  [UnboundLocalError: local variable referenced before assignment](https://blog.csdn.net/yuli_dai/article/details/9326773)
  
