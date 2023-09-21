#include <bits/stdc++.h>
using namespace std;
int dis[26][26];
void solve()
{
    string s;
    cin >> s;
    memset(dis, 63, sizeof dis);

    for (int i = 0; i < 26; i++)
    {
        dis[i][i] = 0;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {

        char u, v;
        int w;
        cin >> u >> v >> w;
        v -= 'a', u -= 'a';
        dis[u][v] = dis[v][u] = min(dis[v][u], w);
    }

    for (int k = 0; k < 26; k++)
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
        {
            continue;
        }
        else
        {
            int cur = 1e9;
            for (int c = 0; c < 26; c++)
            {
                cur = min(cur, dis[s[i] - 'a'][c] + dis[s[s.size() - i - 1] - 'a'][c]);
            }

            if (cur < 1e9)
            {
                ans += cur;
            }
        }
    }

    cout << ans << endl;
}
int main()
{

    solve();

    return 0;
}
