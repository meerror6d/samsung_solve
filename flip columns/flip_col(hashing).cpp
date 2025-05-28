#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1001][1001];

ll getnum(ll A[],ll m){
    ll sum=0,c=0;
    for(ll i=m-1;i>=0;i--){
        sum=sum+A[i]*pow(2,c);
        c++;
    }
    sum+=pow(2,c);
    return sum;

}

ll getones(ll a){
    ll ones=0;
    while(a){
        if(a%2==0)ones++;
        a/=2;
    }
    return ones;

}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    //ll a[1001][1001];

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)cin>>a[i][j];
    }
    ll lists[10001]={0};
    for(ll i=0;i<n;i++){
        ll x=getnum(a[i],m);
        lists[x]++;
    }
    ll ans=0;
    for(ll i=0;i<1000;i++){
        if(lists[i]>0){
            ll s=getones(i);
            if(s<=k){
                if(k%s==0)ans=max(ans,lists[i]);
            }
        }
    }

    cout<<ans<<endl;
}
