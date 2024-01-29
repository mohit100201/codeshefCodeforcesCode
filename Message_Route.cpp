#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int long long int 
#define vi(v) vector<int>v;
#define vec(v,n) vector<int>v(n);
#define vii(v) vector<ll>v;
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rep(i,m,n) for(int i=m;i<n;i++)
#define UMAP(ump) unordered_map<int,int>ump; 
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define SORT(V) sort(v.begin(),v.end());
#define SORT_ARRAY(arr,n) sort(arr,arr+n);
void print_array(int*arr,int n){
for(int i=0;i<n;i++){
cout<<arr[i]<<" ";
}cout<<endl;
}
void print_vector(vector<int>v){
for(auto it : v){
cout<<it<<" ";
}cout<<endl;
}

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 



void solve(){
 int n,m;
 cin>>n>>m;
 vector<int>adj[n+1];
 for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
 } 

 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 vector<int>dis(n+1,1e9);
 vector<int>parent(n+1);

 for(int i=1;i<=n;i++){
    parent[i]=i;
 }

 dis[1]=0;
 pq.push({0,1});

 

 while(!pq.empty()){
    int node=pq.top().second;
    int d=pq.top().first;
    pq.pop();

    for(auto it:adj[node]){
        
        int newd=d+1;
        if(newd<dis[it]){
            dis[it]=newd;
            parent[it]=node;
            pq.push({newd,it});
        }
    }
 }

 if(dis[n]==1e9){
    cout<<"IMPOSSIBLE"<<endl;
    return ;
 }

 cout<<dis[n]+1<<endl;

 vector<int>ans;
 int i=n;
 while(parent[i]!=i){
    ans.push_back(i);
    i=parent[i];
 }
 ans.push_back(1);
 reverse(ans.begin(),ans.end());

 print_vector(ans);





 


 
 
    
    
    
}
int32_t main(){
fast
int t=1;
// cin>>t;
while(t--){
solve();
}
return 0;
}
