#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> adj[V + 1];

    for (int i = 0; i < 3 * E; i += 3)
    {
        int a, b, w;

        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);

    pq.push({0, 0});

    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1)
        {
            continue;
        }

        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int ed = it.second;
            if (!vis[adjnode])
            {
                pq.push({ed, adjnode});
            }
        }
    }

    cout << sum << endl;
}
int main()
{

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
