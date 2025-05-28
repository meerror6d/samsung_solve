#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k,ans=0;
ll a[51][51];

void flip(ll i){
    for(ll j=0;j<n;j++){
        if(a[j][i]==1)a[j][i]=0;
        else a[j][i]=1;
    }

}


void findans(ll kv){

    if(kv==0){
        ll x=0;
        for(ll i=0;i<n;i++){
            ll f=0;
            for(ll j=0;j<m;j++){
                if(a[i][j]==0){f=1;break;}
            }
            if(f==0)x++;
        }
        ans=max(ans,x);
        return;
    }


    for(ll i=0;i<m;i++){
        flip(i);
        findans(kv-1);
        flip(i);
    }
}


int main(){
    cin>>n>>m>>k;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++)cin>>a[i][j];
    }

    findans(k);
    cout<<ans<<endl;


}
