class Trie:
    def __init__(self):
        self.ch=defaultdict(Trie)
        self.sum=0
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root=Trie()
        self.m=defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        p=self.root
        for c in key:
            if p.ch[c]!=None:
                p.ch[c]=p.ch[c]
                p=p.ch[c]
            else:
                p.ch[c]=Trie()
                p=p.ch[c]
            p.sum+=val-self.m[key]
        self.m[key]=val

    def sum(self, prefix: str) -> int:
        p=self.root
        for c in prefix:
            if p==None:
                break;
            p=p.ch[c]
        return p.sum if p!=None else 0

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)