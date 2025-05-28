#include<iostream>
//#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k,ans=0;
ll a[20][20];

ll chk(){

    ll x=0;
    for(ll i=0;i<n;i++){
        ll f=0;
        for(ll j=0;j<m;j++){
            if(a[i][j]==0){f=1;break;}
        }
        if(f==0)x++;
    }
    //m=max(m,x);

    return x;


}

int main(){
    cin>>n>>m>>k;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)cin>>a[i][j];
    }

    for(ll mask=0;mask<(1<<m);mask++){
        if(__builtin_popcount(mask)>k)continue;
        if(__builtin_popcount(mask)%2!=k%2)continue;

        for(ll i=0;i<m;i++){
            if((mask>>i)&1){
                for(ll j=0;j<n;j++){
                    a[j][i]=!a[j][i];
                }
            }
        }
        ans=max(ans,chk());

        for(ll i=0;i<m;i++){
            if((mask>>i)&1){
                for(ll j=0;j<n;j++){
                    a[j][i]=!a[j][i];
                }
            }
        }

    }

    cout<<ans<<endl;


}
