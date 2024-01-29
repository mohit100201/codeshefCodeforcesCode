#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 






void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        

    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    vector<int>dis(n+1);
    for(int i=0;i<n+1;i++){
        dis[i]=1000000000LL *m +1LL;
    }
    vector<int>vis(n+1,0);

    pq.push({0,1});
    dis[1]=0;

    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(vis[node]){
            continue;
        }

        vis[node]=1;

        for(auto it:adj[node]){
            int newd=d+it.second;
            if(newd<dis[it.first]){
                dis[it.first]=newd;
                pq.push({newd,it.first});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }



  
 
 
    
    
    
}
int32_t main(){
int t=1;
// cin>>t;
while(t--){
solve();
}
return 0;
}
