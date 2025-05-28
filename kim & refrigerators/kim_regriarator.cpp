#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=12;
ll n;
pair<ll,ll> a[maxn+2];
ll dis[maxn+2][maxn+2];
ll dp[1<<maxn][maxn];

ll distance(pair<ll,ll>p1,pair<ll,ll>p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int tsp(ll mask,ll pos){
    if(mask==(1<<n)-1){
        return dis[pos+2][1];
    }

    if(dp[mask][pos]!=-1)return dp[mask][pos];

    ll x=INT_MAX;

    for(ll i=0;i<n;i++){
        if(!(mask&(1<<i))){
            ll sumx=dis[pos+2][i+2]+tsp(mask|(1<<i),i);
            x=min(x,sumx);
        }
    }
    return dp[mask][pos]=x;

}

int main(){

    for(ll ii=1;ii<=10;ii++){
        cin>>n;
        cin>>a[0].first>>a[0].second;
        cin>>a[1].first>>a[1].second;

        for(ll i=0;i<n;i++){
            cin>>a[i+2].first>>a[i+2].second;
        }

        for(ll i=0;i<n+2;i++){
            for(ll j=0;j<n+2;j++)
                dis[i][j]=distance(a[i],a[j]);
        }

        for(ll i=0;i<(1<<n);i++){
            for(ll j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }

        ll sum=INT_MAX;

        for(ll i=0;i<n;i++){
            ll c=dis[0][i+2]+tsp(1<<i,i);
            sum=min(sum,c);
        }

        cout<<"# "<<ii<<" "<<sum<<endl;
    }


}
