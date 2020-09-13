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