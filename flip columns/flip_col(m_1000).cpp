#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;

    map<string,ll>freq;
    vector<string>rows(n);

    for(ll i=0; i<n; i++)
    {
        string row="";
        for(ll j=0; j<m; j++)
        {
            char c;
            cin>>c;
            row+=c;
        }
        rows[i]=row;
        freq[row]++;
    }

    ll ans=0;

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        string row = it->first;
        ll cnt = it->second;

        ll zeros=count_if(row.begin(),row.end(),[](char c)
        {
            return c=='0';
        });

        if(zeros<=k && (k-zeros)%2==0)ans=max(ans,cnt);

    }
    cout<<ans<<endl;


}
