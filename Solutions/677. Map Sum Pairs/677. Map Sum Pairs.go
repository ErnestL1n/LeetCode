type Trie struct {
    sum int
    ch [26]*Trie
}

type MapSum struct {
    root *Trie
    m map[string]int
}


/** Initialize your data structure here. */
func Constructor() MapSum {
    return MapSum{
        root: new(Trie),
        m: make(map[string]int),
    }
}

func (this *MapSum) Insert(key string, val int)  {
    p:=this.root
    m:=this.m
    for _,c:=range(key){
        if(p.ch[c-'a']!=nil){
            p.ch[c-'a']=p.ch[c-'a']
            p=p.ch[c-'a']
        }else{
            p.ch[c-'a']=new(Trie)
            p=p.ch[c-'a']
        }
        p.sum+=val-m[key]
    }
    m[key]=val
}


func (this *MapSum) Sum(prefix string) int {
    p:=this.root
    for i:=0;i<len(prefix)&&p!=nil;i+=1{
        p=p.ch[prefix[i]-'a']
    }
    if p!=nil{
        return p.sum
    }else{
        return 0
    }
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */