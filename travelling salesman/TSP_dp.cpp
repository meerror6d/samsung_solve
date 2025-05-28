#include<iostream>
#define ll long long
using namespace std;

ll n;
ll dist[10][10];

ll dp[10000][10000];

ll tsp(ll mask,ll pos)
{
    ll visited_all=(1<<n)-1;

    if(mask==visited_all)
        return dist[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];
    ll ans=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            ll newa=dist[pos][i]+tsp((mask|(1<<i)),i);
            ans=min(ans,newa);
        }
    }
    return dp[mask][pos]=ans;
}


int main()
{
    ll t;cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)cin>>dist[i][j];
        }

        for(ll i=0;i<(1<<n);i++)
        {
            for(ll j=0;j<n;j++)dp[i][j]=-1;
        }

        cout<<tsp(1,0)<<endl;
    }
}
