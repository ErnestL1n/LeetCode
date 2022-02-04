```
while (n != nullptr){
     s.push(exchange(n, n->left));
}
```
is the same to
```
while (n != nullptr){
    s.push(n);
    n = n->left;
}
```
