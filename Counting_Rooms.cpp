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



void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[i][j]=1;

    int delx[4]={-1,0,+1,0};
    int dely[4]={0,+1,0,-1};
    int n=grid.size();
    int m=grid[0].size();

    for(int k=0;k<4;k++){
        int x=i+delx[k];
        int y=j+dely[k];
        if(x<0 || x>=n || y<0 || y>=m){
            continue;
        }

        if(grid[x][y]=='.' && vis[x][y]==0){
            dfs(x,y,grid ,vis);


        }


    }


    
}



void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    rep(i,0,n){
        rep(j,0,m){
            char ch;
            cin>>ch;
            grid[i][j]=ch;
        }
    }

    vector<vector<int>>vis(n,vector<int>(m,0));
int count=0;
rep(i,0,n){
    rep(j,0,m){
        if(grid[i][j]=='.' && vis[i][j]==0){
            // cout<<i<<" "<<j<<endl;
            dfs(i,j,grid,vis);
            count++;
        }
    }
}

cout<<count<<endl;

    
  
 
 
    
    
    
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
