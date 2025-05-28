#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll dist[10][10];

ll tsp(ll mask,ll pos)
{
    ll visited_all=(1<<n)-1;//cout<<visited_all<<endl;

    if(mask==visited_all)
        return dist[pos][0];

    ll ans=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
            ll newa=dist[pos][i]+tsp((mask|(1<<i)),i);
            ans=min(ans,newa);
        }
    }
    return ans;
}

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        cin>>n;

        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)cin>>dist[i][j];

        cout<<tsp(1,0)<<endl;

    }
}
