#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>>adj[n];

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u-1].push_back({v-1,wt});
        adj[v-1].push_back({u-1,wt});
    }

    



    
    
}
int main(){


solve();

return 0;
}
