//optimal version
//Complexity Analysis

//Time: O(m), where m is the number of edges. 
//We go through all edges 3 times. The complexity of the find operation is O(𝛼(n)) as we use both rank and path compression. 
//𝛼(n) can be considered a constant for all practical purposes.
//Memory: O(n) for a disjoined set.


class Solution {
public:
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> ds_both(n+1,-1);
        int used=0;
		//note: vector with "=" just copy values,thus we use auto& as reference
        for(int type=3;type>=1;--type){
            auto ds_one=ds_both;
            auto& ds=type==3?ds_both:ds_one;
            for(auto& e:edges){
                if(e[0]==type){
                    int i=find(ds,e[1]),j=find(ds,e[2]);
                    if(i!=j){
						//if (ds[j] < ds[i])
						//	swap(i, j);
                        ++used;
                        ds[i]+=ds[j];
                        ds[j]=i;
                    }
                }
            }
			//find(ds,1~n)!=-n is OK  ,since nodes are labeled 1~n,and finally should be connect together
            if(type!=3&&ds[find(ds,n)]!=-n)
                return -1;
        }
        return edges.size()-used;
    }
};

class Union{
    vector<int> component;
    int distinctcomponents;
public:
    Union(int n){
        distinctcomponents=n;
        for(int i=0;i<=n;++i)
            component.push_back(i);
    }
    int Find(int a){
        if(component[a]!=a)
            component[a]=Find(component[a]);
        return component[a];
    }
    
    //action function
    bool Unite(int a,int b){
        if(Find(a)==Find(b))
            return false;
        component[Find(a)]=b;
        --distinctcomponents;
        return true;
    }
    
    bool United(){
        return distinctcomponents==1;
    }
    
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int>& b)
             {return a[0]>b[0];});
        int addedEdges=0;
        Union Bob(n),Alice(n);
        for(auto& edge:edges){
            int type=edge[0],start=edge[1],end=edge[2];
            switch(type){
                case 3:
                    addedEdges+=Bob.Unite(start,end)|Alice.Unite(start,end);
                    break;
                case 2:
                    addedEdges+=Bob.Unite(start,end);
                    break;
                case 1:
                    addedEdges+=Alice.Unite(start,end);
                    break;
            }
        }
        return (Bob.United()&&Alice.United())?edges.size()-addedEdges:-1;
    }
};

