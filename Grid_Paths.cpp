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


int f(int ind,int row,int col,string s){
    int n=s.size();
    if(ind==n){
        if(row==6 && col==6){
            return 1;
        }

        return 0;
    }
    if(row<0 || row>=7 || col<0 || col>=7){
        return 0;
    }

    if(row==6 && col==6){
        return 1;
    }

    int ans=0;

    switch (s[ind])
    {
    case 'L':
    ans+=f(ind+1,row,col-1,s);
    
       
        break;
    case 'R':
    ans+=f(ind+1,row,col+1,s);

    break;

    case 'U':
    ans+=f(ind+1,row-1,col,s);

    break;

    case 'D':
    ans+=f(ind+1,row+1,col,s);
    break;

    default:
    //?
    ans+=f(ind+1,row,col-1,s);
    ans+=f(ind+1,row,col+1,s);
    ans+=f(ind+1,row-1,col,s);
    ans+=f(ind+1,row+1,col,s);

    


        break;
    }

    return ans;

}


void solve(){

    string s;
    cin>>s;
    cout<<f(0,0,0,s);


  
 
 
    
    
    
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
