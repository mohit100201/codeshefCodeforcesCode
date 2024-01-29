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







vector<bool>done;
int target,n;
int dfs(int u,int flow, vector<vector<int>>&g){
       done[u]=true;
       if(u==target)return flow;
       for(int v=0;v<n;v++){
           if(g[u][v] && !done[v]){
               int mn=dfs(v,min(flow,g[u][v]),g);
               if(mn>0){
                   g[u][v]-=mn;
                //   cout<<g[u][v]<<endl;
                   return mn;
               }
               
           }
       }
       return 0;
}
void travel(int u,vector<vector<int>>&g){
    done[u]=true;
    for(int v=0;v<n;v++){
        if(g[u][v] && !done[v])
            travel(v,g);
    }
}
vector<int> minimumCut(vector<vector<int>> &g, int s, int t, int N){
    done=vector<bool>(N,false);
    target=t;
     n=N;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(g[j][i])g[i][j]+=g[j][i];
        }
    }
    auto rg=g;
   
    for(long long aug=dfs(s,INT_MAX,rg);aug;aug=dfs(s,INT_MAX,rg)){
        done=vector<bool>(n,false);
        // for(int i=0;i<n;i++){
        // for(int j=0;j<n;j++){
        //     cout<<rg[i][j]<<' ';
        // }
        // cout<<endl;
        // }
        
    }
    done=vector<bool>(n,false);
    travel(s,rg);
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] && done[i] && !done[j]){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    if(ans.empty())
        return {-1};
    return ans;
    
}





void solve(){
  
 int n;
 cin>>n;
 int arr[n];
 input(arr,n);
 int maxi=INT_MIN;
 for(int i=0;i<n;i++){
    maxi=max(maxi,arr[i]);
 }
 vector<vector<int>>adj(maxi+1,vector<int>(maxi+1));

 int e;
 cin>>e;
 while(e--){
    int u,v;
    cin>>u>>v;

   adj[u][v]=1;
   adj[v][u]=1;

    
 }



 int S,D;
 cin>>S>>D;

 vector<int>ans=minimumCut(adj,S,D,maxi+1);

 set<int>s;
 for(auto it:ans){
     if(it!=D) s.insert(it);
 }

 for(auto it:s){
    cout<<it<<" ";
 }cout<<endl;


 






 

 


 



 
    
    
    
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
