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
 vector<vector<char>>grid(n,vector<char>(m));

 rep(i,0,n){
    rep(j,0,m){
        cin>>grid[i][j];
    }
 }

 priority_queue<pair<int,pair<int,int>>,
 vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
 vector<vector<int>>dis(n,vector<int>(m,1e9));

 vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));
 rep(i,0,n){
    rep(j,0,m){
        parent[i][j]={i,j};
    }
 }

 
 int sx,sy,dx,dy;
 rep(i,0,n){
    rep(j,0,m){
        if(grid[i][j]=='A'){
            sx=i;
            sy=j;
        }

        if(grid[i][j]=='B'){
            dx=i;
            dy=j;
        }

    }
 }

 pq.push({0,{dx,dy}});
 dis[dx][dy]=0;

 while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    int row=it.second.first;
    int col=it.second.second;
   
    int d=it.first;
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int nrow=row+delrow[k];
        int ncol=col+delcol[k];
        
        if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
            continue;
        }

        
       
        if(grid[nrow][ncol]=='.' || grid[nrow][ncol]=='A'){
            
            
            int newd=d+1;
        if(dis[nrow][ncol]>newd){
            parent[nrow][ncol]={row,col};
            dis[nrow][ncol]=newd;
            pq.push({newd,{nrow,ncol}});
        }
        }
    }
    

 }

 if(dis[sx][sy]==1e9){
    cout<<"NO"<<endl;
 }
 else{
    cout<<"YES"<<endl;
    cout<<dis[sx][sy]<<endl;
    string ans="";
    int i=sx;
    int j=sy;

    // cout<<i<<" "<<j<<endl;
    // cout<<parent[i][j].first<<" "<<parent[i][j].second<<endl;

    map<pair<int,int>,char>ump;
    ump[{-1,0}]='D';
    ump[{1,0}]='U';
    ump[{0,1}]='L';
    ump[{0,-1}]='R';
   

    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout<<parent[i][j].first<<" "<<parent[i][j].second<<"    ";
            
    //     }cout<<endl<<endl;
    // }

    

    while(parent[i][j].first!=i || parent[i][j].second!=j){
        
        pair<int,int>node={i,j};
        pair<int,int>par={parent[i][j].first,parent[i][j].second};
        pair<int,int>p;
        p.first=node.first-par.first;
        p.second=node.second-par.second;
        ans+=ump[p];
        i=par.first;
        j=par.second;
    
    }

   

cout<<ans<<endl;
    
  
    

    
 }

 

 

 


 
 
    
    
    
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
