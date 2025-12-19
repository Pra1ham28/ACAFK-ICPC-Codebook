int n;
vector<int> bit;

// a should have 1-based indexing. (n+1) size

// +val at index k
void update(int k,int val)
{
    int N = bit.size()-1;
    while(k<=N){
        bit[k]+=val;
        k+=(k&(-k));
    }
}

// prefix-sum upto index k
int prsum(int k)
{
    int N = bit.size()-1;
    if(k>N) k=N;
    int res=0;
    while(k>0){
        res+=bit[k];
        k-=(k&(-k));
    }
    return res;
}

//smallest i such that prsum(0,i)>=val
int query1(int val){
    int n=bit.size();
    int sz=log2(n)+1;
    int ans=0;
    for(int j=sz;j>=0;j--){
        int x=ans+(1LL<<j);
        if(x<=n && bit[x] < val){
            val-=bit[x];
            ans=x;
        }
    }
    ans++;
    return ans;
}

//largest i such that prsum(0,i)>=val
int query2(int val){
    int n=bit.size();
    int sz=log2(n)+1;
    int ans=0;
    for(int j=sz;j>=0;j--){
        int x=ans+(1LL<<j);
        if(x<=n && bit[x] <= val){
            val-=bit[x];
            ans=x;
        }
    }
    return ans;
}
