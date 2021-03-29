## [C++  queue front、stack top return value](https://stackoverflow.com/questions/64189855/c-list-queue-top-return-value)

### Q:
```cpp
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main(){
    priority_queue<pair<int, int>> q;
    q.push({8, 8});
    q.push({19, 19});
    q.push({23, 23});

    while (q.size() > 0){
        auto& cur = q.top();
        q.pop();
        cout << cur.first << " " << cur.second << " "; // returns 19 19 8 8 8 8
    }
    cout << endl;

    list<pair<int, int>> newq;
    newq.push_back({19, 19});
    newq.push_back({8, 8});
    newq.push_back({23, 23});
    while (newq.size() > 0){
        auto& cur = newq.front();
        newq.pop_front();
        cout << cur.first << " " << cur.second << " "; // returns 19 19 8 8 23 23
    }
    cout << endl;
    return 0;
}
```

Iterating over the ```list``` using ```auto&``` vs ```auto``` produces the same output. But I'm trying to understand why if I use ```auto&``` while iterating over the priority queue, the output is wrong. If I change it to ```auto``` my output is correct:
```cpp
    priority_queue<pair<int, int>> q;
    q.push({8, 8});
    q.push({19, 19});
    q.push({23, 23});

    while (q.size() > 0){
        auto cur = q.top();
        q.pop();
        cout << cur.first << " " << cur.second << " "; // returns 23 23 19 19 8 8
    }
    cout << endl;
```    

### A1:
The reason why ```auto &``` does not work here and ```auto``` does, is because with ```auto &``` you get the reference to the object at the ```top()``` of the queue...

... and immediately, on the next line, that object on the top of the queue gets removed and destroyed, leaving you with a dangling reference.

Using that reference, from that point on, results in undefined behavior.

Using ```auto```, instead, copies the object, and the copy continues to exist after the original object gets destroyed.

It is certainly possible that the analogous bug when used with ```std::list``` does not produce observably wrong results, but it's still undefined behavior. "Undefined behavior" means exactly that: anything can happen. Including getting the expected results, purely by accident. A good static analysis tool, like [valgrind](https://valgrind.org/), should be able to catch this bug.



### A2:
```auto &``` is a reference to another object. Not a copy of another object. ```auto cur``` is a full fledged object. ```auto &cur``` is a reference to some other object. What do you think is the difference between ```auto cur``` and ```auto &cur```? ```auto &cur=q.top()``` is a reference to the object at the top of the queue. ```pop()``` destroys that object. It is no more. It ceased to exist. It's pining for the fjords. It's an ex-object. The fact that there was a reference to the object, somewhere, doesn't prevent it from getting destroyed.
