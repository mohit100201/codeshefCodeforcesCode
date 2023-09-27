#include <bits/stdc++.h>
using namespace std;
const int N = 200003;
const int bits = 30;
int prefix[N][bits];
int arr[N];

void buildPrefix(int n)
{
    // occurence of j th bit in first i elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (arr[i] & (1 << j))
            {
                prefix[i + 1][j] = prefix[i][j] + 1;
            }
            else
            {
                prefix[i + 1][j] = prefix[i][j];
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

    buildPrefix(n);

    int q;
    cin >> q;
    vector<int> res;
    while (q--)
    {
        int l, k;
        cin >> l >> k;

        if (arr[l - 1] < k)
        {
            res.push_back(-1);
            continue;
        }

        int low = l;
        int high = n;
        int ans = l;

        while (low <= high)
        {

            int mid = (low+high) / 2;
            int  temp = 0;

            for (int j= 0; j < 30; j++)
            {
                if ((prefix[mid][j] - prefix[l - 1][j]) == (mid - l + 1))
                {
                    temp += (1 << j);
                }
            }

            if (temp >= k)
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        res.push_back(ans);
    }

    for(auto it:res){
        cout<<it<<" ";
    }cout<<endl;
}
int main()
{

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // return 0;
}
