struct DSU {
    vector<int> par, rnk;
    DSU(int n){
        par.assign(n+1,0);
        rnk.assign(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int find_set(int x){
        if(par[x]==x) return x;
        return par[x]=find_set(par[x]);
    }
    bool union_set(int a, int b){
        int p1=find_set(a), p2=find_set(b);
        if(p1==p2) return 0;
        if(rnk[p1]>rnk[p2]){
            par[p2]=p1;
            rnk[p1]+=rnk[p2];
        }
        else{
            par[p1]=p2;
            rnk[p2]+=rnk[p1];
        }
        return 1;
    }
};
